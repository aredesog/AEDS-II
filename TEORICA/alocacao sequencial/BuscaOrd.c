#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int buscaOrd(int x){

    int i = 0; //indice inical
    L1[n + 1].chave = x; //guarda o valor no fim do vetor

    while(L[i].chave < x){ //enquanto o valor for menor percorro o vetor
        i++;
    }

    if(i = (n + 1) || L[i].chave != x){ //se a chave é a ultima do vetor a posição que encontrei for diferente do x retorna -1
        return -1;
    } else {
        return i; //retorna psoição encontrada caso ela seja valida
    }


}