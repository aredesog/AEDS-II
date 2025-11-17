#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

typedef struct {
    int *vetor;   // vetor de prioridades
    int tamanho;  // capacidade máxima
    int fim;      // índice do último elemento
} Heap;

Heap* heap_inicializa(int tamanho);
void heap_insere(Heap *h, int prioridade);
bool ehVazia(Heap *h);
bool ehCheia(Heap *h);
int heap_remove(Heap *h);
void heap_libera(Heap *h);

#endif
