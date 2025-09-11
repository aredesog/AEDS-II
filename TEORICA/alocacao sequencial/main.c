#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

No L[5] = { //Vetor de struct criado para testar a primeira funcao de busca (busca1)
    {10, 100},
    {20, 101},
    {30, 102},
    {40, 103},
    {50, 104}
};
int n = 5; //n determina o tamanho do vetor de busca1

No L1[6] = { //Vetor de struct criado para testar a segunda funcao de busca (busca2)
    {10, 100},
    {20, 101},
    {30, 102},
    {40, 103},
    {50, 104}
};
int n2 = 6; //n2 determina o tamanho do vetor de busca2
int m = 5; //controla o tamanho atual da lista

pilha p[6] = {
    {10, 100},
    {20, 101},
    {30, 102},
    {40, 103},
    {50, 104},
};

int topo = 4;

fila fi[6] = {
    {10, 100},
    {20, 101},
    {30, 102},
    {40, 103},
    {50, 104},
};

int r = -1, f = -1;

int main(){

    //int x1 = 10; //Variavel utilizada para armazenar a chave que buscamos em busca2
    //printf("\nResultado de busca de %d na lista:%d\n", x1, busca2(x1)); //Exibimos o resultado da funcao busca2 passando o x2

    //int x2 = 10; //Variavel utilizada para armazenar a chave que buscamos em busca2
    //printf("\nResultado de busca de %d na lista:%d\n", x2, busca2(x2)); //Exibimos o resultado da funcao busca2 passando o x2

    //int x3 = 50; 
    //printf("\nResultado de busca de %d na lista:%d\n", x3, buscaOrd(x3));

    //int x4 = 40; 
    //printf("\nResultado de busca de %d na lista:%d\n", x4, buscaBin(x4)); 

    //No no;
    //no.chave = 60;
    //no.valor = 105;

    //printf("\nPosicao 6 no vetor antes de inserir: %d\n", L1[5]);
    //printf("\nResultado de insercao do no na lista: %d\n", insere(no));
    //printf("\nPosicao 6 no vetor depois de inserir: %d\n", L1[5]);


   //removeLista(20);

   /* for(int i = 0; i < 5; i++){
        printf("\nPosicao: %d  Chave: %d\n",i,L[i].chave);
    }*/

    //printf("\nAntes de inserir:\n");
    /*for(int i = 0; i <= topo; i++){
        printf("\nPosicao: %d  Chave: %d\n",i,p[i].chave);
    }*/

    //pilha no;
    //no.chave = 60;
    //no.valor = 105;
    //printf("\nValor do topo: %d\n",inserePilha(no));

    //printf("\nDepois de inserir:\n");

    /*
    printf("\nTopo: %d\n",topo);
    for(int i = 0; i <= topo; i++){
        printf("\nPosicao: %d  Chave: %d\n",i,p[i].chave);
    }*/
    
   //removePilha();
 
    /*
    printf("\nTopo: %d\n",topo);
    for(int i = 0; i <= topo; i++){
        printf("\nPosicao: %d  Chave: %d\n",i,p[i].chave);
    }*/
    /*
    fila no;
    no.chave = 60;
    no.valor = 105;

    insereFila(no);

    removeFila();

    for(int i = 0; i <= m; i++){
        printf("\nPosicao: %d  Chave: %d\n",i,fi[i].chave);
    }

    return 0;
    */
}