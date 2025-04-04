# 编译器设置
CXX = g++
CXXFLAGS = -std=c++17

# 目标文件
TARGETS = generator.exe code_a.exe code_b.exe stress_test.exe

# 默认目标
all: $(TARGETS)

# 通用编译规则
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# 运行对拍
run: all
	./stress_test.exe

# 清理
ifeq ($(OS),Windows_NT)
    RM = del /f /q
else
    RM = rm -f
endif

clean:
ifeq ($(OS),Windows_NT)
	$(RM) file_copier
	@echo Cleaning test data...
	$(RM) *.exe
	$(RM) *.txt
else
	rm -f file_copier *.o *~ *.exe
	@echo Cleaning test data...
	rm -f input_*.txt output_a_*.txt output_b_*.txt error_log.txt
endif
	@echo Cleanup complete.

.PHONY: all run clean