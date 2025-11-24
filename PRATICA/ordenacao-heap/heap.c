#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HEAP* heap_inicializa(int tamanho) {
    HEAP *h = (HEAP*) malloc(sizeof(HEAP));

    h->vetor = (int*) malloc(sizeof(int) * tamanho);
    h->tam = tamanho;
    h->fim = -1;

    return h;
}

int ehVazia(HEAP *h) {
    return (h->fim == -1);
}

int ehCheia(HEAP *h) {
    return (h->fim == h->tam - 1);
}

void heap_insere(HEAP *h, int prioridade) {
    if (ehCheia(h)) {
        printf("Heap cheia!\n");
        return;
    }

    h->fim++;
    int i = h->fim;

    h->vetor[i] = prioridade;

    // ---- MAX-HEAP: sobe enquanto o pai for menor ----
    while (i > 0) {
        int pai = (i - 1) / 2;

        if (h->vetor[pai] >= h->vetor[i])
            break;

        int aux = h->vetor[i];
        h->vetor[i] = h->vetor[pai];
        h->vetor[pai] = aux;

        i = pai;
    }
}

int heap_remove(HEAP *h) {
    if (ehVazia(h)) {
        printf("Heap vazia!\n");
        return -1;
    }

    int retorno = h->vetor[0];

    h->vetor[0] = h->vetor[h->fim];
    h->fim--;

    int i = 0;

    // ---- MAX-HEAP: desce enquanto algum filho for maior ----
    while (1) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        int maior = i;

        if (esq <= h->fim && h->vetor[esq] > h->vetor[maior])
            maior = esq;

        if (dir <= h->fim && h->vetor[dir] > h->vetor[maior])
            maior = dir;

        if (maior == i)
            break;

        int aux = h->vetor[i];
        h->vetor[i] = h->vetor[maior];
        h->vetor[maior] = aux;

        i = maior;
    }

    return retorno;
}
