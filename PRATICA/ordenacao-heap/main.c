#include <stdio.h>
#include "heap.h"

int main() {
    int tamanho;
    printf("Digite o tamanho da heap: ");
    scanf("%d", &tamanho);

    HEAP *h = heap_inicializa(tamanho);

    int op, valor;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Inserir\n");
        printf("2 - Remover maior\n");
        printf("3 - Mostrar heap\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("Valor: ");
            scanf("%d", &valor);
            heap_insere(h, valor);
            break;

        case 2:
            valor = heap_remove(h);
            if (valor != -1)
                printf("Removido: %d\n", valor);
            break;

        case 3:
            printf("Heap: ");
            for (int i = 0; i <= h->fim; i++)
                printf("%d ", h->vetor[i]);
            printf("\n");
            break;

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}
