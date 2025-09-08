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

/*
        O trabalho com ponteiros e memoria da aula 4, foi baseado na explicação de aritimetica com ponteiros, no qual se passa de um endereço de memoria p/
    outro atraves da soma com um inteiro * o sizeof(int), pois ai ira redefinir o local correto.
        Já na função malloc temos uma auxiliar de memoria, na qual ela guarda valores para certos momentos necessarios entretanto necessita 
    ser liberada apos sua ultilização com o free(variavel!)        
*/