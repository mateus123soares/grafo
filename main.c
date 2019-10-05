#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "cdisjunto.h"
#include "pilha.h"
#include "heap.h"

int main(){

//Funções que realiza a abertura e leitura do arquivo txt

char cont[50],*palv;
int TAMANHO,chave,chave_adj,peso;
FILE *arquivo;
Grafo *grafo=inicia();
	
	if((arquivo=fopen("grafo.txt","r"))==NULL){ //Busca no arquivo texto o numero de elementos 
		printf("erro na abertura \n");
	}

	fgets(cont,20,arquivo);
	TAMANHO=atoi(cont);
	grafo=lst_grafo(grafo,TAMANHO); // Criando Grafos

	while((fgets(cont,200,arquivo))!=NULL){ // faz a separacao das palavras a cada ; ou \n			
		palv = strtok(cont,";");
		chave=atoi(palv);
		palv = strtok(NULL,";");
		chave_adj=atoi(palv);
		palv = strtok(NULL,"\n");
		peso=atoi(palv);
		grafo=adjacencia(grafo,chave,chave_adj,peso); //Criando Lista de adjacencias 
	}
	fclose(arquivo);

// Fim da manipulação do arquivo

// Menu do programama
int e;	
	while(e!=9){

		printf("Digite uma opção: \n");
		printf("1 - Mostrar lista de adjacencia: \n");
		printf("2 - Conjuntos Disjuntos \n");
		printf("3 - Busca em profundidade DFS \n");
		printf("4 - Busca em largura BFS \n");
		printf("5 - Menu HEAP\n");
		printf("6 - Algoritmo de Kruskal \n");
		printf("7 - Algoritmo de Prim \n");
		printf("8 - Algoritmo de Dijkstra\n");
		printf("9 - sair: \n");
		printf("Digite: ");
		scanf("%d",&e);
			if(e==1){ 	// Mostra na tela a lista de adjacencias 
				Nodo *no = grafo->ListaNodos;
				no=grafo->ListaNodos;
				 while (no != NULL){
				 	Aresta *aux=no->adj;
    					while(aux != NULL){
    						printf("Chave %d adjacencia %d Peso %d \n",no->chave,aux->chave_adj,aux->peso,aux->chave_part);	
    						aux=aux->prox;
    					}
    			    no = no->prox;
    			}	
			}

			//CONJUNTOS DISJUNTOS

			if(e==2){ 
				int i=0,m=0,z=0,a,b;
				int *conj;
				while(z!=5){
					printf("1 - Criar conjuntos disjuntos\n");
					printf("2 - Fazer União\n");
					printf("3 - Encontrar Representante\n");
					printf("4 - Mostrar Conjuntos\n");
					printf("5 - sair\n");
					scanf("%d",&z);	
						if(z==1){
							printf("Informe quantidade de conjuntos\n");
							scanf("%d",&m);
							conj=Makeset(m);
						}
						
						if(z==2){
							printf("UNIAO DE: \n");
							scanf("%d",&a);
							printf("UNIAO COM: \n");
							scanf("%d",&b); 
							Union(Findset(a,conj),Findset(b,conj),conj);			
						}
						if(z==3){
							printf("informe valor\n");
							scanf("%d",&a);
							b=Findset(a,conj);
							printf("Representante: %d \n ",b);		
						}
						if(z==4){
							for(i=0;i< m;i++){
								printf("%d\t",conj[i]);
							}
							printf("\n");
						}
						if(z==5){
							free(conj);
						}
				}
			}

			// FIM CONJUNTOS DISJUNTOS //



			// ALGORITMOS DE BUSCA: OK //			
			if(e==3){  // DFS
				int v;
					printf("Informe a chave do grafo\n");
					scanf("%d",&v);
					DFS(grafo,v,TAMANHO);
			}
			
			if(e==4){ // BFS
				int v;
				printf("Informe a chave do grafo\n");
				scanf("%d",&v);
    			BFS(grafo,v,TAMANHO);
			}

			 // FIM ALGORITMOS DE BUSCA //


			// HEAP//

			if(e==5){ // MENU COM FUNÇOES HEAP
				int z=0,tamanho=1;
				Heap *heap;
				heap=(Heap*)malloc(sizeof(Heap)*1);
				Heap *elemento=(Heap*)malloc(sizeof(Heap));
					while(z!=5){
						printf("Digite uma opção\n");
						printf("1 - Gerar HEAP com arestas \n");
						printf("2 - Remover elemento da HEAP\n");
						printf("3 - Printar estado atual da HEAP\n");
						printf("4 - Mostrar raiz da HEAP\n");
						printf("5 - SAIR\n");
						scanf("%i",&z);
							if(z==1){ //GERANDO HEAP APARTIR DAS ARESTAS EM FUNÇÃO DO PESO
								Nodo *no = grafo->ListaNodos;
								no=grafo->ListaNodos;
									 while (no != NULL){
								 		Aresta *aux=no->adj;
				    						while(aux != NULL){
					    						elemento->peso=aux->peso;
												elemento->chave_part=aux->chave_part;
												elemento->chave_dest=aux->chave_adj; 
					    						heap=buildHeap(heap,tamanho++,elemento);
					    						aux=aux->prox;
				    						}
				    			    	no = no->prox;
				    				}	
								printHeap(heap,tamanho);
							}
							if(z==2){ // REMOVENDO RAIZ DA HEAP
								int num;
								elemento=deleteHeap(heap,tamanho);
									if(tamanho!=0){
										tamanho--;
										printf("PESO removido é: %d\n",elemento->peso);
										printf("CHAVE PART removido é: %d\n",elemento->chave_part);
										printf("CHAVE DEST removido é: %d\n",elemento->chave_dest);
										//printHeap(heap,tamanho);
									}
									else{
										printf("HEAP VAZIA\n");
									}
							}
							if(z==3){ // MOSTRANDO ESTADO ATUAL DA HEAP
								printHeap(heap,tamanho);
							}
							if(z==4){ // MOSTRAR NODO RAIZ 
								int raiz;
									if(tamanho!=0){
										raiz=getRaiz(heap);
										printf("Raiz é: %d \n",raiz);
									}
									else{
										printf("HEAP VAZIA\n");
									}
							}
							if(z==5){ //LIBERANDO HEAP
								free(heap);
							}
					}
			}
			// FIM HEAP //
			
			// ALGORITMOS GERADORES DE ARVORES MINIMAS

			if(e==6){ //Kruskal 
				Kruskal(grafo,TAMANHO);
			}
			if(e==7){
				Prim(grafo,TAMANHO);
			}
			if(e==8){
				Dijkstra(grafo,TAMANHO);
			}

			// FIM ALGORITMO GERADORES DE ARVORES MINIMAS
	} 
return 0;
}