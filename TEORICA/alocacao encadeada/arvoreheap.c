#include <stdio.h>

#define MAX 100 // tamanho máximo da heap

// Estrutura da heap
typedef struct {
int dados[MAX];
int tamanho;
} Heap;

// Função para trocar dois valores
void troca(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

// Função para "subir" um elemento (heapify-up)
void subir(Heap *h, int i) {
int pai = (i - 1) / 2;
if (i > 0 && h->dados[i] > h->dados[pai]) {
troca(&h->dados[i], &h->dados[pai]);
subir(h, pai);
}
}

// Função para "descer" um elemento (heapify-down)
void descer(Heap *h, int i) {
int maior = i;
int esq = 2 * i + 1;
int dir = 2 * i + 2;

// Verifica se o filho esquerdo é maior
if (esq < h->tamanho && h->dados[esq] > h->dados[maior])
maior = esq;

// Verifica se o filho direito é maior
if (dir < h->tamanho && h->dados[dir] > h->dados[maior])
maior = dir;

// Se o maior não for o pai, troca e continua descendo
if (maior != i) {
troca(&h->dados[i], &h->dados[maior]);
descer(h, maior);
}
}

// Inicializa a heap
void inicializar(Heap *h) {
h->tamanho = 0;
}

// Insere um novo valor na heap
void inserir(Heap *h, int valor) {
if (h->tamanho >= MAX) {
printf("Heap cheia!\n");
return;
}

h->dados[h->tamanho] = valor;
subir(h, h->tamanho);
h->tamanho++;
}

// Remove o maior valor (raiz)
int removerMax(Heap *h) {
if (h->tamanho == 0) {
printf("Heap vazia!\n");
return -1;
}

int max = h->dados[0];
h->tamanho--;
h->dados[0] = h->dados[h->tamanho];
descer(h, 0);

return max;
}

// Mostra o conteúdo da heap (em array)
void mostrarHeap(Heap *h) {
printf("Heap: ");
for (int i = 0; i < h->tamanho; i++)
printf("%d ", h->dados[i]);
printf("\n");
}

// Programa principal
int main() {
Heap h;
inicializar(&h);

inserir(&h, 10);
inserir(&h, 40);
inserir(&h, 30);
inserir(&h, 5);
inserir(&h, 15);

mostrarHeap(&h);

printf("Removendo o maior elemento: %d\n", removerMax(&h));
mostrarHeap(&h);

return 0;
}