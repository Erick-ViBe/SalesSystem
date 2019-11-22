generadordecodigos.o: generadorcodigos.c
	gcc generadorcodigos.c -c -Wall
main.o: main.c
	gcc main.c -c -Wall

a.out: main.o generadorcodigos.o
	gcc main.o generadorcodigos.o

run: a.out
	./a.out

clean:
	rm -f *.o a.out
