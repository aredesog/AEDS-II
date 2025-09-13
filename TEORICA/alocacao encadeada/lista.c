#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int chave; //lista
    int valor; //valor a ser encontrado na lista
    struct lista *prox; //ponteiro para o proximo elemento da lista
}no;



void buscaLista(no *ptlista, int x, no **ant, no **pont){ //ponteiros para auxilio do decorrer da lista 

    no *ptr = ptlista->prox; //ponteiro que aponta para o proximo elemento da lista
    no *ant = ptlista; //ponteiro para se refenciar ao anterior
    *pont = NULL; //ponteiro para quando se achar o valor desejado na lista

    while(ptr != NULL){ //enquanto o elemento que eu preoucro nao é o proximo na lista 
        if(ptr->chave < x){ //se o elemento que eu busco é menor que atual
            *ant = ptr; //o anterior vira ptr
            ptr = ptr->prox; //ptr pula para o proximo
        } else if(ptr == x){ //se o elemento que eu busco e igual ao atual
            *pont = ptr; //o elemento foi achado e foi marcado por pont
            ptr = NULL; //ptr sai do loop
        } else { //se o elemento nao estiver na lista
            ptr = NULL; //sai do loop
        }
    }
}

int insereLista(no *ptlista, no *inserido){
    int retorno = -1; //retorna caso não dê
    no *ant; no *pont; //ponteiros de auxilio
}