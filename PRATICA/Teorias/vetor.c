#include <stdio.h>
#include <stdlib.h>

struct proximo{
    int valor;
};

int remove_numero(int L[]){
    int numero;
    
    printf("Qual numero quer remover? ");
    scanf("%d", &numero);
    
    // Procura o número no vetor
    for (int i = 0; i < 10; i++){
        if(numero == L[i]){
            printf("Numero %d encontrado na posicao: %d\n", numero, i);
            
            // Move todos os elementos à esquerda
            for(int j = i; j < 9; j++){
                L[j] = L[j + 1];
            }
            
            // Coloca 0 na última posição
            L[9] = 0;

            //tira uma casa do vetor
            
            return 1; // Indica que removeu com sucesso
        }
    }
    
    printf("Numero %d nao encontrado no vetor!\n", numero);
    return 0; // Indica que não encontrou
}

int adiciona_valor(){

    int valor;

    printf("Qual valor quer adicionar: ");
    scanf("%d", &valor);

    //verifica se esta cheio

    //se nao insere o valor em ordem crescente 

    //mostra o novo vetor
    
}

int main(){
    int L[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("Vetor original: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", L[i]);
    }
    printf("\n");

    remove_numero(L);

    printf("Vetor apos remocao: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", L[i]);
    }
    printf("\n");

    return 0;
}