//Biblioteca Heap

struct heap{
	int chave_part;
	int chave_dest;
	int peso;
};
typedef struct heap Heap;

//função que constroi um novo heap com o elemento inserido
Heap *buildHeap (Heap *heap,int tamanho,Heap *elemento);

//função para deletar o elemento da heap
Heap *deleteHeap(Heap *heap,int tamanho);

//função para imprimir o estado atual da heap
void printHeap(Heap *heap,int tamanho);

//função sift-down para posicionar os elementos da heap
void siftDown(Heap *heap,int tamanho);

//função percolate para posicionar os elementos da heap
void percolate(Heap *heap,int tamanho);

//retorna o maior da heap 
int getRaiz(Heap *heap);