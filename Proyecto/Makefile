contigua.o: supermercado.c
	gcc supermercado.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o supermercado.o
	gcc main.o supermercado.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o supermercado.o
