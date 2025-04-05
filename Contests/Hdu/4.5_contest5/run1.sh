#!/bin/bash

# 用法: ./bash.sh x.cpp

# 检查参数
if [ $# -ne 1 ]; then
    echo "用法: $0 <cpp文件>" >&2
    exit 1
fi

CPP_FILE="$1"
EXECUTABLE="${CPP_FILE%.*}.out"

# 检查文件是否存在
if [ ! -f "$CPP_FILE" ]; then
    echo "错误: 文件 $CPP_FILE 不存在" >&2
    exit 2
fi

# 清理旧可执行文件
rm -f "$EXECUTABLE"

# 编译
echo "编译 $CPP_FILE ..."
g++ -std=c++17 -O2 "$CPP_FILE" -o "$EXECUTABLE" || exit 3

# 运行
./"$EXECUTABLE"