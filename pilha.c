#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


// Funções de manipulação da pilha Inicia,Adicionar,Remover

Descritor *Ini_pilha(void){ 
	
	Descritor *p=(Descritor*)malloc(sizeof(Descritor));
	p->topo=NULL;
	p->quant=0;

return p;
}

void Push_pilha(Descritor *p, int v){

	Pilha *novo=(Pilha*)malloc(sizeof(Pilha));
	novo->chave=v;
	novo->prox=NULL;
		if(p->topo==NULL){
			p->topo=novo;
			p->quant++;
		}
		else{
			novo->prox=p->topo;
			p->topo=novo;
			p->quant++;
		}
}

int Pop_pilha(Descritor *p){
	Pilha *aux;
	int v;
	aux=p->topo;
		if(p->topo != NULL){
			aux=p->topo;
			v=aux->chave;
			p->topo=aux->prox;
			free(aux);
			p->quant--;
		}
		else{
			p->topo==NULL;
			p->quant=0;
		}
return v;
}
