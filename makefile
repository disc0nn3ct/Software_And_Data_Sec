c=gcc
all:
	gcc one.c -o client.o 
	./client.o
	@echo "================================================================="
	g++ main.cpp -o aaa.o 
	./aaa.o 

clean: 
	rm -rf *.o
