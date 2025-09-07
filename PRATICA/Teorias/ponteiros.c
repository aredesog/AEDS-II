#include <stdio.h>
#include <stdlib.h>



int main(){
    //variaveis de ponteiro
    int num1 = 10;
    int *pont1 = &num1;
    int **pont2 = &pont1;

    //conteudo de pont2 == endereço de pont1
    printf("%p\n", pont2);
    printf("%p\n", &pont1);
    printf("----------\n");

    //conteudo de pont1 == endereço de num1
    printf("%p\n", *pont2);
    printf("%p\n", &num1);
    printf("---------\n");


    //conteudo de num1
    printf("%d\n", **pont2);
    printf("%d\n", num1);
    printf("---------\n");

    
    //Até aqui, aprendemos sobre passagem de endereço de ponteiros, e também de ponteiros de ponteiros, conteúdo dentro de variaveis de ponteiro
    //e fizemos testes para alertar certamente sobre o que estamos dizendo.
    
}
    

    void dobra(int *n){
        *n = (*n) * 2;
        printf("conteudo de n: %p\n", n);
        printf("conteudo apontado por n: %d\n", *n);
    }

    int main(){
        //passagem de parâmetro por valor x por referência
        int num1 = 10;
        dobra(&num1); //passagem de parâmetro por referência
        printf("endereco de num1: %p\n", &num1);
        printf("valor de num1: %d\n", num1);
    }

    //Até aqui, aperndemos sobre a passagem de parametro de pobteiros em funções, o que de fato facilita muito em certas ocasiões.
