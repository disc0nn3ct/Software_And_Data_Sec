c=gcc
all:
	g++ main.cpp -o aaa.o 
	./aaa.o 
	
clean: 
	rm -rf *.o
