#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

typedef struct {
    int chave;
}REGISTRO;

int busca1(int x){
    int i = 0; //Variavel auxiliar 
    int busca = -1; //caso venha a nao encontrar

    while(i < n){ //percorre o vetor
        if(L[i].chave == x){ //se o valor desejado for igual
            busca = i; //salva o valor em busca
            break;
        } else  {
            i++; //adiciona +1 caso nao encontre ainda
                }
    }
    return busca; //retorna o valor da busca
}


int busca2(int x){
    int i = 0; //Variavel de controle do loop
    L1[n].chave = x; //Armazena a chave que queremos no final do vetor

    while(L1[i].chave != x){ //Percorro todo o vetor enquanto a chave que procuro for diferente da chave atual
        i++; //Incrementa 1 no contador
    }

    if(i != n){ //Ao percorrer o vetor conferimos se a posicao encontrada e diferente da ultima posicao do vetor
        return i; //Caso seja encontramos a chave no vetor e retornamos a posicao
    }else{
        return -1; //Caso nao seja, a chave nao se encontra no vetor e retornamos -1
    }

}
