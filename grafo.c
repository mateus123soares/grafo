#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "pilha.h"
#include "fila.h"
#include "cdisjunto.h"
#include "heap.h"

//FUNÇÕES QUE MANIPULÃO O GRAFO

Grafo *inicia(void){ //Inicia o Descritor do Grafo

	Grafo *grafo=(Grafo*)malloc(sizeof(Grafo));
	grafo->ListaNodos=NULL;
	grafo->tamanho=0;

return grafo;
}

Grafo *lst_grafo(Grafo *grafo,int x){ // Cria a lista de forma recursiva
		
	if(x==0){
		return grafo;
	}
	else{
		Nodo *novo=(Nodo*)malloc(sizeof(Nodo));
		novo->chave=x; 
		novo->prox = NULL;
		novo->adj = NULL;	
		
		if(grafo->ListaNodos==NULL){
			grafo->ListaNodos = novo;
			grafo->tamanho++;
			lst_grafo(grafo,x-1);
		}
		else{
			novo->prox = grafo->ListaNodos;
			grafo->ListaNodos = novo;
			grafo->tamanho++;
			lst_grafo(grafo,x-1);
		}
		
	}
}

Grafo *adjacencia(Grafo *grafo,int chave,int chave_adj,int peso){ // Função que cria as adjacencias
Nodo *aux=grafo->ListaNodos;
Nodo *aux2=grafo->ListaNodos;
	
	while(aux != NULL){
		if(aux->chave==chave){
			aux2=aux;
		}
		aux=aux->prox;
	}

	Aresta *novo=(Aresta*)malloc(sizeof(Aresta));
	novo->chave_adj=chave_adj;
	novo->chave_part=chave;
	novo->peso=peso;
	novo->prox=NULL;
	
	if(aux2->adj==NULL){
		aux2->adj=novo;
	}
	else{
		novo->prox=aux2->adj;
		aux2->adj=novo;
	}

return grafo;
}

// FIM FUNÇÕES DE MANIPILAÇÃO DO GRAFO

//FUNÇÕES DE BUSCA DFS E BFS


void *DFS(Grafo *grafo,int v,int n){
	Descritor *p;
	Nodo *aux2;
	Aresta *aux;
	p=Ini_pilha();
	int val,t=0,x=0,i=0;
	int visited[n];	
	
	for(i=0;i<n;i++){ //zerando o vetor de visitados
		visited[i]=0;			
	}
		Push_pilha(p,v);
			while(p->topo != NULL){ //verifica se a pilha esta vazia
				t=0;
				val=Pop_pilha(p);
				for(i=1;i<n;i++){
					if(visited[i]==val){
						t=1;
					}
				}
				if(t!=1){
				 visited[x++]=val;// Marca adjacencia como visitado
				}
				aux2=grafo->ListaNodos; //reseta grafo
					while(aux2->chave != val){ //achando posição do nodo
						aux2=aux2->prox;
					}
						for(aux=aux2->adj;aux != NULL;aux=aux->prox){	//vendo as adjacencias do nodo 
							t=0;
								for(i=0;i<n;i++){
									if(visited[i]==aux->chave_adj){
										t=1;
									}
								}
								if(t!=1){
									Push_pilha(p,aux->chave_adj); //adiciona a adjacencia a fila
								}	
						}

			}
			printf("Solução é:\n");
			for(i=0;i<x;i++){ //mostra o vetor de visitados
				printf(" %d, ",visited[i]);
			}
			printf("\n");
			free(p);
}
void *BFS(Grafo *grafo,int v,int n){

	Desc_fila *f;
	Aresta *aux;
	Nodo *aux2;
	f=Ini_fila();
	int val,t=0,x=0,i=0;
	int visited[n];	
	
		for(i=0;i<n;i++){ //zerando o vetor de visitados
			visited[i]=0;			
		}	
			coloca_fila(f,v);
				while(f->ini!=NULL){
					val=tira_fila(f);
					t=0;
					for(i=0;i<n;i++){
						if(visited[i]==val){
							t=1;
						}
					}
					if(t!=1){
						visited[x++]=val;
					}
					aux2=grafo->ListaNodos; //reseta grafo
						while(aux2->chave != val){ //achando posição do nodo
							aux2=aux2->prox;
						}
							for(aux=aux2->adj;aux != NULL;aux=aux->prox){
								t=0;
									for(i=0;i<n;i++){
										if(visited[i]==aux->chave_adj){
											t=1;
										}
									}
											if(t!=1){
												coloca_fila(f,aux->chave_adj);
											}
						}
				}
		printf("\n");
		printf("Solução é:\n");
		for(i=0;i<x;i++){ //mostra o vetor de visitados
			printf(" %d, ",visited[i]);
		}
		free(f);
}

//FIM FUNÇÕES DE BUSCA DFS E BFS


// ALGORITMOS KRUSKAL , PRIM , DIJKSTRA

void *Kruskal(Grafo *grafo, int t){
	
	int TAMANHO=1,x=0,flag;
	Aresta *solucao=(Aresta *)malloc(sizeof(Aresta)*50);
	Heap *elemento=(Heap *)malloc(sizeof(Heap));
	Heap *heap=(Heap *)malloc(sizeof(Heap)*1);
	Nodo *no = grafo->ListaNodos;
	no=grafo->ListaNodos;
		 while (no != NULL){
			Aresta *aux=no->adj;
			while(aux != NULL){
				elemento->peso=aux->peso;
				elemento->chave_part=aux->chave_part;
				elemento->chave_dest=aux->chave_adj; 
				heap=buildHeap(heap,TAMANHO++,elemento);
				aux=aux->prox;
			}
		   	no = no->prox;
		}
	int *conj;
	conj=Makeset(t);
		while(TAMANHO != 0){
			elemento=deleteHeap(heap,TAMANHO--);

			if(Findset(elemento->chave_part,conj) != Findset(elemento->chave_dest,conj)){

				solucao[x].chave_part=elemento->chave_part;
				solucao[x].chave_adj=elemento->chave_dest;
				solucao[x].peso=elemento->peso;
				conj=Union(Findset(elemento->chave_part,conj),Findset(elemento->chave_dest,conj),conj);
				x++;

			}
		}
		x--;
	    while(x >= 0){
	    	printf("PARTIDA %d DESTINO %d PESO %d \n",solucao[x].chave_part,solucao[x].chave_adj,solucao[x].peso);	
		   	x--;
	   }
					
}

void *Prim(Grafo *grafo, int t){
	
	int *conj,dest,part,peso;
	conj=Makeset(t);

	Aresta *solucao =(Aresta*)malloc(sizeof(Aresta)*50);
	Heap *elemento=(Heap*)malloc(sizeof(Heap));
	Heap *heap=(Heap*)malloc(sizeof(Heap)*1);
	Nodo *no=grafo->ListaNodos;
	Aresta *aux;

	int nodo,x=0,tamanho=1;
		printf("Informe o nodo de partida \n");
		scanf("%d",&nodo);
			solucao[0].chave_adj=nodo;
			solucao[0].chave_part=nodo;
			solucao[0].peso=0;
			x++;
			while (no != NULL){
				if(no->chave == nodo){
				Aresta *aux=no->adj;
					while(aux != NULL){
						elemento->peso=aux->peso;
						elemento->chave_part=aux->chave_part;
						elemento->chave_dest=aux->chave_adj;				
		    			heap=buildHeap(heap,tamanho++,elemento);	  						
		  				aux=aux->prox;
		    		}
		    	}
				no = no->prox;
			}

				while(tamanho != 0){
					elemento=deleteHeap(heap,tamanho--);
					dest=elemento->chave_dest;
					part=elemento->chave_part;
					peso=elemento->peso;
					if(Findset(elemento->chave_dest,conj) != Findset(elemento->chave_part,conj)){
						Nodo *no = grafo->ListaNodos;
						no=grafo->ListaNodos;
					 		while (no != NULL){
					 			if(dest == no->chave){
					 				Aresta *aux=no->adj;
	    							while(aux != NULL){
										elemento->peso=aux->peso;
										elemento->chave_part=aux->chave_part;
										elemento->chave_dest=aux->chave_adj;
	    								heap=buildHeap(heap,tamanho++,elemento);			
	    								aux=aux->prox;
	    							}
	    						}
	    			    		no = no->prox;
	    					}
	    				Union(Findset(dest,conj),Findset(part,conj),conj);

	    				solucao[x].chave_part=part;
						solucao[x].chave_adj=dest;
						solucao[x].peso=peso;
						x++;
    				}	
				}

		x--;
	    while(x >= 0){
	    	printf("PARTIDA %d DESTINO %d PESO %d \n",solucao[x].chave_part,solucao[x].chave_adj,solucao[x].peso);	
		   	x--;
	   }
}

void *Dijkstra(Grafo *grafo, int t){
	int D[t],Pi[t],nodo,tamanho=1,x=0,part,dest,peso,flag;
	Aresta *solucao =(Aresta*)malloc(sizeof(Aresta)*50);
	Heap *elemento=(Heap*)malloc(sizeof(Heap));
	Heap *heap=(Heap*)malloc(sizeof(Heap)*1);
	Nodo *no=grafo->ListaNodos;
	Aresta *aux;
	for(int x=0; x < t;x++){
		D[x]=10000;
		Pi[x]=0;
	}
		printf("Informe o nodo de partida \n");
		scanf("%d",&nodo);
		part=nodo;
		x=0;
		D[nodo-1]=0;
		solucao[x].chave_adj=part;
		solucao[x].chave_part=part;
		solucao[x].peso=0;
		x++;
			while (no != NULL){
				if(no->chave == nodo){
				Aresta *aux=no->adj;
					while(aux != NULL){
						elemento->peso=aux->peso;
						elemento->chave_part=aux->chave_part;
						elemento->chave_dest=aux->chave_adj;				
		    			heap=buildHeap(heap,tamanho++,elemento);	  						
		  				aux=aux->prox;
		    		}
		    	}
				no = no->prox;
			}
			while(tamanho != 0){
				elemento=deleteHeap(heap,tamanho--);
				dest=elemento->chave_dest;
				part=elemento->chave_part;
				peso=elemento->peso;
				flag=0;
				for(int i=0;i<=t;i++){
					if(solucao[i].chave_adj==elemento->chave_dest){
						flag=1;
					}
				}
				if(flag!=1){
					solucao[x].chave_adj=dest;
					solucao[x].chave_part=nodo;
					x++;
				}
					if(D[dest-1] > D[part-1] + peso){
						Pi[dest-1]=part;
						D[dest-1]=D[part-1] + peso;
						Nodo *no=grafo->ListaNodos;
							while (no != NULL){
								if(no->chave == dest){
									Aresta *aux=no->adj;
									while(aux != NULL){
										elemento->peso=aux->peso;
										elemento->chave_part=aux->chave_part;
										elemento->chave_dest=aux->chave_adj;				
						    			heap=buildHeap(heap,tamanho++,elemento);	  						
						  				aux=aux->prox;
						    		}
						    	}
								no = no->prox;
							}
					}
			}
			int v;
		for(int l=1;l<t;l++){
			v=solucao[l].chave_adj;
				for(int j=0; j < t;j++){
					if(solucao[j].chave_adj == v){
						solucao[j].peso = D[v-1];
					}
				}
		}
		x--;
	    while(x >= 0){
	    	printf("PARTIDA %d DESTINO %d PESO %d \n",solucao[x].chave_part,solucao[x].chave_adj,solucao[x].peso);	
		   	x--;
	   }
}		

// FIM ALGOTIRMOS KRUSKAL , PRIM , DIJKSTRA