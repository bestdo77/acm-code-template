#!/bin/bash

if [ $# -ne 1 ]; then
    echo "用法: $0 <cpp文件>" >&2
    exit 1
fi

# 动态生成输入文件名（例如 D.cpp → d.txt）
CPP_FILE="$1"
BASE_NAME=$(basename "${CPP_FILE%.*}" | tr '[:upper:]' '[:upper:]')  # 转小写
INPUT_FILE="${BASE_NAME}.txt"

# 检查输入文件是否存在
if [ ! -f "$INPUT_FILE" ]; then
    echo "错误: 输入文件 $INPUT_FILE 不存在" >&2
    exit 2
fi

# 生成可执行文件名
EXECUTABLE="${CPP_FILE%.*}.out"

# 验证.cpp文件
if [[ ! "$CPP_FILE" =~ \.cpp$ ]]; then
    echo "错误: 必须指定.cpp文件" >&2
    exit 3
fi

if [ ! -f "$CPP_FILE" ]; then
    echo "错误: 文件 $CPP_FILE 不存在" >&2
    exit 4
fi

# 清理旧文件
rm -f "$EXECUTABLE"

# 编译程序
echo -e "\033[34m编译中...\033[0m"
g++ -std=c++17 -O2 "$CPP_FILE" -o "$EXECUTABLE"
if [ $? -ne 0 ]; then
    echo -e "\033[31m编译失败\033[0m" >&2
    exit 5
fi

# 分割测试用例
echo -e "\033[34m分割测试用例...\033[0m"
TEST_CASE_DIR=$(mktemp -d)
awk -v dir="$TEST_CASE_DIR" '
    /^---$/ { 
        close(outfile); 
        idx++; 
        outfile = dir "/testcase_" idx ".txt"; 
        next 
    }
    { 
        if (!outfile) {
            idx = 1;
            outfile = dir "/testcase_1.txt"
        }
        print > outfile 
    }
' "$INPUT_FILE"

# 遍历所有测试用例
for testcase in "$TEST_CASE_DIR"/testcase_*.txt; do
    echo -e "\n\033[32m===== 测试用例: $(basename "$testcase") =====\033[0m"
    
    # 显示输入内容
    echo -e "\033[33m输入数据:\033[0m"
    cat "$testcase"
    # echo -e "\033[32m$(printf '%.0s─' $(seq 1 $(tput cols)))\033[0m"
    echo -e "\n"
   
    # 准备临时文件
    TIME_OUTPUT=$(mktemp)
    STDOUT_TEMP=$(mktemp)
    STDERR_TEMP=$(mktemp)
    
    # 运行测试
    {
        /usr/bin/time -f "%e %U %S %M" -o "$TIME_OUTPUT" \
        stdbuf -o0 -e0 ./"$EXECUTABLE" < "$testcase" \
            > "$STDOUT_TEMP" 2>"$STDERR_TEMP"
    } 

        # 先显示标准输出（绿色）
    if [ -s "$STDOUT_TEMP" ]; then
        echo -e "\033[32m===== 标准输出 =====\033[0m"
        cat "$STDOUT_TEMP"
    fi

    # 再显示标准错误（红色）
    if [ -s "$STDERR_TEMP" ]; then
        echo -e "\n\033[31m===== 标准错误 =====\033[0m"
        cat "$STDERR_TEMP"
    fi

    # 解析性能结果
    if [ -s "$TIME_OUTPUT" ]; then
        {
            read real_time user_time sys_time mem_kb
            # 过滤可能的额外信息（如Command exited...）
            [[ "$real_time" =~ [0-9] ]] || real_time=0
            [[ "$mem_kb" =~ [0-9] ]] || mem_kb=0
        } < "$TIME_OUTPUT"
    else
        echo -e "\033[31m警告: 未捕获到性能统计数据\033[0m" >&2
        real_time=0
        user_time=0
        sys_time=0
        mem_kb=0
    fi

    # 单位转换（安全传递变量）
    real_time_ms=$(awk -v t="$real_time" 'BEGIN {printf "%.3f", t * 1000}')
    user_time_ms=$(awk -v t="$user_time" 'BEGIN {printf "%.3f", t * 1000}')
    sys_time_ms=$(awk -v t="$sys_time" 'BEGIN {printf "%.3f", t * 1000}')
    mem_mb=$(awk -v mem="$mem_kb" 'BEGIN {printf "%.2f", mem / 1024}')

    # 输出性能报告
    echo -e "\n\033[33m===== 性能统计 =====\033[0m"
    echo -e " 实际用时: ${real_time_ms} ms"
    echo -e " 用户CPU : ${user_time_ms} ms"
    echo -e " 系统CPU : ${sys_time_ms} ms"
    echo -e " 内存峰值: ${mem_mb} MB"
    # 清理临时文件
    rm -f "$TIME_OUTPUT" "$STDOUT_TEMP" "$STDERR_TEMP"
done

# 最终清理
rm -rf "$TEST_CASE_DIR"
echo -e "\n\033[32m所有测试用例执行完成！\033[0m"