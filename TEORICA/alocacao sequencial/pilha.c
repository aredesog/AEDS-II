#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int inserePilha(pilha no){
    
    int retorno = -1; //variavel de retorno

    if(topo != m){  //se a pilha esta cheia nao pode inserir
        topo = topo + 1; //atualiza o indice do topo
        p[topo] = no; //insere o no na pilha
        retorno = topo; //retorna a posaição inserida
    }
    return retorno;
}

No *removePilha(){

    pilha *retorno = NULL; //variavel de controle de inicio = 0
    
    if(topo != 0){ //se a pilha nao estiver vazia
        retorno = &p[topo]; //prepara o endereço do no removido
        topo--; //diminiu o indice do topo
    }
    return retorno;
}