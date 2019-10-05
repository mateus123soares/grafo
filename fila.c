#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Desc_fila *Ini_fila(void){
	Desc_fila *f =(Desc_fila*)malloc(sizeof(Desc_fila));
	f->ini=NULL;
	f->fim=NULL;
	f->quant=0;
	return f;
}

void coloca_fila(Desc_fila *f,int v){
	Fila *novo=(Fila*)malloc(sizeof(Fila));
	novo->chave=v;
	novo->prox=NULL;
		if(f->ini==NULL && f->fim==NULL){
			f->ini=novo;
			f->fim=novo;
			f->quant++;
		}
		else{
			f->fim->prox=novo;
			f->fim=novo;
			f->quant++;
		}
}

int tira_fila(Desc_fila *f){
	Fila *aux;
	int v;
	if(f->ini->prox==NULL){
		aux=f->ini;
		v=aux->chave;
		f->ini=NULL;
		f->fim=NULL;
		free(aux);
		f->quant--;
		return v;
	}
	else{
		aux=f->ini;
		v=aux->chave;
		f->ini=aux->prox;
		free(aux);
		f->quant--;
		return v;
	}
}