#ifndef HEAP_H
#define HEAP_H

typedef struct heap {
    int *vetor;
    int tam;
    int fim;
} HEAP;

HEAP* heap_inicializa(int tamanho);
void heap_insere(HEAP *h, int prioridade);
int heap_remove(HEAP *h);

// === implementações requeridas ===
int ehVazia(HEAP *h);
int ehCheia(HEAP *h);

#endif
