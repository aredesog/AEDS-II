# include <stdio.h>
# include <stdlib.h>

/*Alocação Encadeada, apesar de fazer um uso maior de memoria
tem seus beneficios como quando não se conhece os dados que estão sendo 
ultilizados na busca, faz a remoção de um valor com maior facilidade do que 
a Alocação Sequencial, e isso também ocorre com a Inclusão.

-> A Alocação Encadeada faz o uso dos ponteiros em sua classificação.
*/



typedef struct REGISTRO {
    int chave;
    struct REGISTRO *prox;
} REGISTRO;


// Busca encadeada para lista NÃO ordenada: retorna ponteiro para o nó encontrado ou NULL, e atualiza o anterior
REGISTRO* buscaEncadeada(REGISTRO *inicio, int chave, REGISTRO **ant) {
    *ant = NULL;
    REGISTRO *ptr = inicio;
    while (ptr != NULL) {
        if (ptr->chave == chave) {
            return ptr;
        }
        *ant = ptr;
        ptr = ptr->prox;
    }
    return NULL;
}


int main() {
    REGISTRO *inicio = NULL, *novo, *ant, *res;
    int i, valor;
    // Criando lista encadeada com valores 1 a 10
    for(i = 10; i >= 1; i--) {
        novo = (REGISTRO*)malloc(sizeof(REGISTRO));
        novo->chave = i;
        novo->prox = inicio;
        inicio = novo;
    }

    printf("Qual valor voce deseja buscar? ");
    scanf("%d", &valor);

    res = buscaEncadeada(inicio, valor, &ant);
    if(res != NULL) {
        printf("Valor %d encontrado!\n", valor);
    } else {
        printf("Valor %d não encontrado.\n", valor);
    }

    // Libera memória
    while(inicio != NULL) {
        REGISTRO *tmp = inicio;
        inicio = inicio->prox;
        free(tmp);
    }
    return 0;
}