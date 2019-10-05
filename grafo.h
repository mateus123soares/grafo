// Struct do grafo 

struct nodo{
	
	int chave;
	struct nodo *prox;
	struct aresta *adj;
};
typedef struct nodo Nodo;

struct grafo{
	
	struct nodo *ListaNodos;
	int tamanho;
};
typedef struct grafo Grafo; 

struct aresta{
	int chave_adj;
	int chave_part;
	int peso;
	struct aresta *prox;
};
typedef struct aresta Aresta;

// Funçoes de manipulação do grafo: ok

Grafo *inicia(void);
Grafo *adjacencia(Grafo *grafo,int chave,int chave_adj,int peso);
Grafo *lst_grafo(Grafo *grafo,int x);

// Funções de busca DFS BFS: ok

void *DFS(Grafo *grafo,int v,int n);
void *BFS(Grafo *grafo,int v,int n);

// Funções arvores geradoras minimas: ok

void *Kruskal(Grafo *grafo, int t);
void *Prim(Grafo *grafo,int t);
void *Dijkstra(Grafo *grafo, int t);
