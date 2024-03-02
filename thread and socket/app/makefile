INCLUDEDIR=-I/root/work1/tools -I/root/work1/api
LIBDIR=-L/root/work1/tools -L/root/work1/api

all:demo01

demo01:demo01.cpp
	 g++ -o demo demo01.cpp $(INCLUDEDIR) $(LIBDIR) -lpublic  -lmyapi 

clean:
	rm -f demo01
