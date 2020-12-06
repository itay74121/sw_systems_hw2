gcc=gcc -Wall -g
all: main 

main: main.o mybanklib.a
	${gcc} main.o mybanklib.a -o main

mybanklib.a: mybank.o 
	ar -rcs mybanklib.a mybank.o

mybank.o: mybank.c mybank.h
	${gcc} -c mybank.c -o mybank.o

main.o: main.c
	${gcc} -c main.c -o main.o

clean:
	rm *.o *.a main 



