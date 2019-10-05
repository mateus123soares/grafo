// Struct das pilhas 
struct pilha{

	int chave;
	struct pilha *prox;
};
typedef struct pilha Pilha;

struct Desc_pilha {

	Pilha *topo;
	int quant;
};
typedef struct Desc_pilha Descritor;


// Funções de manipulação da pilha: ok

Descritor *Ini_pilha(void);
void Push_pilha(Descritor *p, int v);
int Pop_pilha(Descritor *p);

