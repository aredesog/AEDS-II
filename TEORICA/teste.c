# include <stdio.h>
# include <stdlib.h>

/*Alocação Encadeada, apesar de fazer um uso maior de memoria
tem seus beneficios como quando não se conhece os dados que estão sendo 
ultilizados na busca, faz a remoção de um valor com maior facilidade do que 
a Alocação Sequencial, e isso também ocorre com a Inclusão.

-> A Alocação Encadeada faz o uso dos ponteiros em sua classificação.
*/


typedef struct
{
    int chave

}REGISTRO;

int buscaEncadeada(REGISTRO L[], int* pont, int* ant){

    int* ptlista = L;
    int* ptr;

    *ant = *ptlista;
    *pont = NULL;
    *ptr = ptlista


    while(*ptr =! 0){
        if(*ptr.chave < L[]){
            *ant = *ptr;
            *ptr = *ptr.prox;
        } else if(ptr.chave = L[]){
            *pont = *ptr;
            *ptr = NULL;
        }

    }

}

int main() {

REGISTRO L[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int* pont, *ant;
int valor;

printf("Qual valor você deseja buscar? ");
scanf("%d", &valor);

buscaEncadeada(L, &pont, &ant);

}