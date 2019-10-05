main:	main.o grafo.o cdisjunto.o pilha.o fila.o heap.o
	gcc main.o grafo.o cdisjunto.o pilha.o fila.o heap.o -o exe -g
	rm	*.o
	./exe
main.c:
	gcc -c main.c -g

grafo.o: grafo.c grafo.h
	gcc -c grafo.c -g
	
cdisjunto.o: cdisjunto.c cdisjunto.h
	gcc -c cdisjunto.c -g

pilha.o: pilha.c pilha.h
	gcc -c pilha.c -g

fila.0: fila.c fila.h
	gcc -c fila.c -g

heap.o: heap.c heap.h
	gcc -c heap.c -g
	
clean:
	rm	*.o
