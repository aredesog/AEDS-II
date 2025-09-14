#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int chave;
    int valor;
    struct fila *prox;
}no;

void insereFila(no **insere, no **incio, no **fim){

    if( *fim != NULL){ //confere se a fila pode ter inserção
        (*fim)->prox = insere; //insere no fim da fila
    } else { //caso contrario insere o primeiro elemento
        *incio =insere; //insere o primeiro elemento
    }
        *fim = insere; //apos insercao o fim aponta para o elemento inserido pois ele e o novo ultimo elemento
}

no *removeFila(no **inicio, no **fim){
    no *retorno = NULL;

    if(*inicio != NULL){
        retorno = *inicio; //retorno a ponta para elemento a ser removido
        *inicio = (*inicio)->prox; //inicio aponta para o segundo elemento

        if(*inicio == NULL){ //se o elemento removido for o ultimo da fila o fim também a ponta para NULL pois a fila ficou vazia
            *fim = NULL; //fim aponta para nulo
        }
    }
    return retorno; //retorna NULL ou elemento removido
}

void liberaFila(no **inicio, no **fim){
    while(*inicio != NULL){ //enquanto existir elementos na fila
        no *aux = *inicio; //guardo o primeiro elemento
        *inicio = (*inicio)->prox; //inicio aponta para os egundo
        free(aux); //limpa o primeiro elemento da memoria
    }
    *fim = NULL; //no fim do loop a fila fica fazia entao fim também a ponta para NULL
}

void imprimeFila(no *inicio){
    while (inicio != NULL){ //enquanto existir elementos na fila
        printf("\nChave: %d Valor: %d",inicio->chave, inicio->valor); //imprime o valor e a chave do elemeno atual
        inicio = inicio->prox; //inicio a ponta para o proximo elemento
    }
}

no *alocaFila(int x){
    no *novoNo = malloc(sizeof(no)); //aloca o novo no na memoria

    if(novoNo == NULL){ //verificacao de alocacao de memoria
        printf("\nErro ao alocar memoria\n");
        return NULL; //retorna NULL indicado erro
    }

    novoNo->chave = x; //atribui o inteiro a chave
    novoNo->valor = x * 10; //atribui um valor
    novoNo->prox = NULL; //proximo do novo elemento sempre e NULL

    return novoNo; //retorna o endereco do novo no
}
int main(){

    no *inicio = NULL; //inicio e fim comecam nulos pois a fila esta vazia
    no *fim = NULL;

    no *no1 = alocaFila(1); //criando nos para teste
    insereFila(&inicio, &fim, no1); //realizando insercoes para teste
    
    no *no2 = alocaFila(2);
    insereFila(&inicio, &fim, no2);
    
    no *noRemovido1 = removeFila(&inicio, &fim); //testaando remocao
    printf("\nPrimeira remocao");

    no *no3 = alocaFila(3);
    insereFila(&inicio, &fim, no3);

    no *no4 = alocaFila(4);
    insereFila(&inicio, &fim, no4);

    no *no5 = alocaFila(5);
    insereFila(&inicio, &fim, no5);
    
    imprimeFila(inicio); //imprime a fila para visulizacao de insercao e remocao
    
    no *noRemovido2 = removeFila(&inicio, &fim); //remove outro elemento
    printf("\n\nSegunda remocao");

    imprimeFila(inicio); //imprime a fila novamente

    liberaFila(&inicio, &fim); //libera tanto os elementos removidos quando a fila inteira
    free(noRemovido1);
    free(noRemovido2);
    
    if(inicio == NULL && fim ==NULL){ //confere se os ponteiros inicio e fim de fato ficaram nulos indicando que a fila esta vazia
        printf("\nInicio e fim == NULL\n");
    }

    return 0;
}
