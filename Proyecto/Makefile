supermercado.o: supermercado.c
	gcc supermercado.c -c -Wall

main.o: main.c
	gcc main.c -c -Wall

a.out: main.o supermercado.o
	gcc main.o supermercado.o -lm

run: a.out
	./a.out

clean:
	rm -f a.out main.o supermercado.o
