#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//Biblioteca Heap


//função sift-down para posicionar os elementos da heap
void siftDown(Heap *heap,int tamanho){
	int i,aux2,aux,aux3;
	i=0;
	while(i<tamanho-1){
		if(heap[i].peso > heap[i+1].peso){
			aux=heap[i+1].peso;
			heap[i+1].peso=heap[i].peso;
			heap[i].peso=aux;
			aux2=heap[i+1].chave_part;
			heap[i+1].chave_part=heap[i].chave_part;
			heap[i].chave_part=aux2;
			aux3=heap[i+1].chave_dest;
			heap[i+1].chave_dest=heap[i].chave_dest;
			heap[i].chave_dest=aux3;
		}
	i++;
	}
	
}

//função que constroi um novo heap com o elemento inserido
Heap *buildHeap(Heap *heap,int tamanho,Heap *elemento){
	Heap *vetor;
	vetor=(Heap*)malloc(sizeof(Heap)*(tamanho+1));
	for (int i = 0; i < tamanho; ++i){
			vetor[i].peso=heap[i].peso;
			vetor[i].chave_part=heap[i].chave_part;
			vetor[i].chave_dest=heap[i].chave_dest;
		}
	vetor[tamanho-1].peso=elemento->peso;
	vetor[tamanho-1].chave_part=elemento->chave_part;
	vetor[tamanho-1].chave_dest=elemento->chave_dest;

	heap=vetor;
	percolate(heap,tamanho);
	return heap;
}

//função para deletar o elemento da heap
Heap *deleteHeap(Heap *heap,int tamanho){
	int min;
	Heap *vetor;
	Heap *elemento=(Heap*)malloc(sizeof(Heap));
	tamanho--;
	elemento->peso=heap[0].peso;
	elemento->chave_part=heap[0].chave_part;
	elemento->chave_dest=heap[0].chave_dest;
	heap[0].peso=heap[tamanho-1].peso;
	heap[0].chave_part=heap[tamanho-1].chave_part;
	heap[0].chave_dest=heap[tamanho-1].chave_dest;
	vetor=heap;
	heap=(Heap*)malloc(sizeof(Heap)*tamanho-1);
	heap=vetor;
	siftDown(heap,tamanho);
	return(elemento);
}

//função para imprimir o estado atual da heap
void printHeap(Heap *heap,int tamanho){

	if(tamanho!=0){
		printf("HEAP: \n");
			for(int i=0;i<tamanho-1;i++){
				printf("PARTIDA [%d] ",heap[i].chave_part);
				printf("DESTINO {%d} ",heap[i].chave_dest);
				printf("PESO %d ",heap[i].peso);
				printf("\n");
			}
		printf("\n");
	}
	else{
		printf("HEAP VAZIA\n");
	}
}

//função percolate para posicionar os elementos da heap
void percolate(Heap *heap,int tamanho){
	int i,aux,aux2,aux3;
	i=tamanho-1;
	while(i!=0){
		if(heap[i].peso < heap[i-1].peso){
			aux=heap[i-1].peso;
			heap[i-1].peso=heap[i].peso;
			heap[i].peso=aux;
			aux2=heap[i-1].chave_part;
			heap[i-1].chave_part=heap[i].chave_part;
			heap[i].chave_part=aux2;
			aux3=heap[i-1].chave_dest;
			heap[i-1].chave_dest=heap[i].chave_dest;
			heap[i].chave_dest=aux3;
		}
	i--;
	}
}

//retorna o menor da heap 
int getRaiz(Heap *heap){
	int raiz; 

		raiz=heap[0].peso;
	
	return raiz;	
}