#include <stdio.h>
#include <stdlib.h>

//alocação de memoria de forma dinamica

int main(){
    int num_elementos = 4; //numero de vezes que quero ultilizar a memoria alocada
    int *pont = malloc(num_elementos* sizeof(int)); //malloc armazena um valor na memoria de forma temporaria
    
    *pont = 100;

    printf("%d\n", sizeof(int));


    for(int i = 0; i < num_elementos; i++){
        printf("%p\n", (pont + i)); // endereço contido em pont + i * sizeof(int) |(4bytes)|
    }

    free(pont); //libera a memoria ultilizada pelo malloc

    

}    