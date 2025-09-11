#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int inserir(No no){ //passa o paramentro de No com aplido de no, para evitar o uso de structs repetidamente

    if(m < n2){ // verifica se a lista está cheia
        if(busca2(no.chave) == -1){  //se a chave nao esta na lista 
            L[m] = no; //insere o elemento
            m++; //atualiza o contador da lista
            return m; //retorna o tamanho da lista
        } else {
                return -1; // caso o elemeto ja esteja na lista
        } 
    } else {
            return -2; //caso a lista esteja cheia
        }

}

No *removeLista(int x){
    No *retorno = NULL; //variavel que guarda o indice do item a ser removido

    if(m != 0){ 
        int indice = busca2(x); //realiza a busca do numero a ser removido

        if(indice != -1){ 
            retorno = &L[indice];// salva o endereço a ser removido(ponteiro necessita de endereço)
                for(int i = indice; i < m; i++){ //loop para corrigir os valores da lista
                    L[i] = L[i + 1]; //salva o prox. valor da lista no valor atual
                }
                m--; //diminui a lista atual
        } 
    }   
    return retorno;
}