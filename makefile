c=gcc
all:
	g++ main.cpp -o main.o 
	strip main.o
	./main.o 
clean: 
	rm -rf *.o
