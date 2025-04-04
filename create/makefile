# 定义目标文件名
TARGET = file_copier

# 定义编译器
CC = g++

# 定义编译选项（支持 C++17）
CXXFLAGS = -std=c++17

# 定义源文件
SRCS = create.cpp

# 默认目标，生成可执行文件
all: $(TARGET)

# 生成可执行文件
$(TARGET): $(SRCS)
	$(CC) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# 运行程序
run: $(TARGET)
	./$(TARGET)

# 清理生成的文件
clean:
	rm -f $(TARGET) *.o *~ *.exe

.PHONY: all run clean