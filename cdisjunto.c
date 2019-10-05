#include <stdio.h>
#include <stdlib.h>
#include "cdisjunto.h"

int *Makeset(int n){
	int *conj = (int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
			conj[i] = (i+1);
	}
	return conj;
}

int Findset(int i,int *conj){
	if(conj[i - 1] == i){
		return i;
	}
	else{
		conj[i - 1] = Findset(conj[i - 1],conj);
		return conj[i - 1];
	}
}

int *Union(int i, int j,int *conj){
int aux;
	if(i < j){
		aux = j;
		j = i;
		i = aux;
	}
	conj[i - 1] = Findset(j,conj);

	return conj;
}	