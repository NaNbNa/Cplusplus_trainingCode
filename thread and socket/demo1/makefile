# 定义编译选项  
COMPILE_FLAGS = -g 
  
# 定义目标程序列表  
PROGRAMS = demo1 demo2 demo3 demo4 
# 适用于只依赖server的
SERVER = demo5 demo6 demo7 demo8

#显示指定依赖文件--适用于只依赖server的
SERVER_obj = %: %.o server.o

# 执行
all: $(PROGRAMS) $(SERVER)

# 规则

%.o: %.cpp %.h 
	g++ $(COMPILE_FLAGS) -c $< -o $@

$(SERVER): $(SERVER_obj)
	g++ $(COMPILE_FLAGS) -o $@ $^  

$(PROGRAMS): %: %.o
	g++ $(COMPILE_FLAGS) -o $@ $^  
 
  
# 清理规则  
clean:  
	rm -f $(PROGRAMS) $(SERVER) *.o 