all: main.o ex1.o
	gcc main.o ex1.o -o lab3

main.o: main.c ex1.h
	gcc -c main.c

ex1.o: ex1.c ex1.h
	gcc -c ex1.c

clean:
	rm -f *.o lab3
