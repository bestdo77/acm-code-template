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

# 创建临时文件
TIME_OUTPUT=$(mktemp)
STDOUT_TEMP=$(mktemp)
STDERR_TEMP=$(mktemp)

# 显示输入样例
echo -e "\n\033[32m===== 输入样例 ($INPUT_FILE) =====\033[0m"
cat "$INPUT_FILE"
echo -e "\n\033[32m==================================\033[0m"

# 运行程序并分离输出流
echo -e "\n\033[34m运行程序 (输入来自 $INPUT_FILE)\033[0m"
{
    # 强制无缓冲输出并捕获性能数据
    /usr/bin/time -f "%e %U %S %M" -o "$TIME_OUTPUT" \
    stdbuf -o0 -e0 ./"$EXECUTABLE" < "$INPUT_FILE" >"$STDOUT_TEMP" 2>"$STDERR_TEMP"
} 2>/dev/null

# 先显示标准输出（绿色）
if [ -s "$STDOUT_TEMP" ]; then
    echo -e "\033[32m===== 标准输出 =====\033[0m"
    cat "$STDOUT_TEMP"
    echo -e "\033[32m====================\033[0m"
fi

# 再显示标准错误（红色）
if [ -s "$STDERR_TEMP" ]; then
    echo -e "\n\033[31m===== 标准错误 =====\033[0m"
    cat "$STDERR_TEMP"
    echo -e "\033[31m====================\033[0m"
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