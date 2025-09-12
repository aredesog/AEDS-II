#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

insereFila(fila no){
    int retorno = -2; //caso a lista esteja cheia

    int prov =  (r + 1) % (m + 1); //resto da divisão do ultimo +1 pelo tamanho.
    if(prov != f){ //se o proximo valor de insercao nao for o primeiro item a fila nao esta cheio e pode inserir
            r = prov; //retaguarda a ponta pro ultimo item
            fi[r] = no; //insere o no na fila
            retorno = r; //variavel retorna a posicao inserida
            
            if(f == -1){ //se o primeiro item foi inserido na fila f aponta para 0 (primeira posicao valida)
                f = 0; //frente aponta para 0
            }
    }
    return retorno; //variavel de retorno retorna
}

fila *removeFila(){
    fila *retorno = NULL; //retorna null se nao poder remover

    if(f != -1){ //se a fila nao estiver vazia remove
        retorno = &fi[f]; // retorna o endereço do item a ser removido
        if(f == r){ //se existir um unico item na fila frente e eretaguarda aponta para -1
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % (m + 1); //caso haja mais itens na lista a apos a aremoção, frente tem que apontar pro proximo item da fila
        }
    }
    return retorno;
}