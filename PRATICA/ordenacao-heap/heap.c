#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// ---------- INICIALIZA -----------

Heap* heap_inicializa(int tamanho) {
    Heap *h = (Heap*) malloc(sizeof(Heap));
    h->vetor = (int*) malloc(sizeof(int) * tamanho);
    h->tamanho = tamanho;
    h->fim = -1;
    return h;
}

// ---------- VERIFICAÇÕES ----------

bool ehVazia(Heap *h) {
    return h->fim == -1;
}

bool ehCheia(Heap *h) {
    return h->fim == h->tamanho - 1;
}

// ---------- INSERÇÃO (MAX-HEAP) ----------

void heap_insere(Heap *h, int prioridade) {
    if (ehCheia(h)) {
        printf("Heap cheia!\n");
        return;
    }

    h->fim++;
    int i = h->fim;
    h->vetor[i] = prioridade;

    // subir (MAX-HEAP)
    while (i > 0) {
        int pai = (i - 1) / 2;

        if (h->vetor[pai] >= h->vetor[i]) break;

        int aux = h->vetor[i];
        h->vetor[i] = h->vetor[pai];
        h->vetor[pai] = aux;

        i = pai;
    }
}

// ---------- REMOÇÃO (REMOVE O MAIOR) ----------

int heap_remove(Heap *h) {
    if (ehVazia(h)) {
        printf("Heap vazia!\n");
        return -1;
    }

    int retorno = h->vetor[0];
    h->vetor[0] = h->vetor[h->fim];
    h->fim--;

    int i = 0;

    // descer (MAX-HEAP)
    while (1) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        int maior = i;

        if (esq <= h->fim && h->vetor[esq] > h->vetor[maior])
            maior = esq;

        if (dir <= h->fim && h->vetor[dir] > h->vetor[maior])
            maior = dir;

        if (maior == i) break;

        int aux = h->vetor[i];
        h->vetor[i] = h->vetor[maior];
        h->vetor[maior] = aux;

        i = maior;
    }

    return retorno;
}

void heap_libera(Heap *h) {
    free(h->vetor);
    free(h);
}

// ---------- PROGRAMA PRINCIPAL ----------

int main() {
    int tam;
    printf("Tamanho da heap: ");
    scanf("%d", &tam);

    Heap *h = heap_inicializa(tam);

    int op, x;

    do {
        printf("\n---- MENU ----\n");
        printf("1 - Inserir\n");
        printf("2 - Remover maior\n");
        printf("3 - Mostrar heap\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch(op) {
        case 1:
            printf("Valor a inserir: ");
            scanf("%d", &x);
            heap_insere(h, x);
            break;

        case 2:
            x = heap_remove(h);
            if (x != -1)
                printf("Removido: %d\n", x);
            break;

        case 3:
            printf("Heap: ");
            for (int i = 0; i <= h->fim; i++)
                printf("%d ", h->vetor[i]);
            printf("\n");
            break;

        case 4:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (op != 4);

    heap_libera(h);

    return 0;
}
