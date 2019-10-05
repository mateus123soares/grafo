// Struct das filas 
struct fila{

	int chave;
	struct fila *prox;
};
typedef struct fila Fila;

struct Desc_fila {
	
	Fila *ini;
	Fila *fim;
	int quant;
};
typedef struct Desc_fila Desc_fila;


// Funções de manipulação da pilha: ok

Desc_fila *Ini_fila(void);
void coloca_fila(Desc_fila *f, int v);
int tira_fila(Desc_fila *f);
