#include <stdio.h>
#include <stdlib.h>

struct proximo{ // usei pra nada
    int valor;
};

int remove_numero(int L[], int *tamanho){  // Recebe ponteiro para tamanho
    int numero;
    
    printf("Qual numero quer remover? ");
    scanf("%d", &numero);
    
    // Procura o número no vetor
    for (int i = 0; i < *tamanho; i++){  // Usa tamanho atual
        if(numero == L[i]){
            printf("Numero %d encontrado na posicao: %d\n", numero, i);
            
            // Move todos os elementos à esquerda
            for(int j = i; j < *tamanho - 1; j++){  // Até tamanho-1
                L[j] = L[j + 1];
            }
            
            (*tamanho)--;  // Diminui o tamanho em 1
            
            return 1; // Indica que removeu com sucesso
        }
    }
    
    printf("Numero %d nao encontrado no vetor!\n", numero);
    return 0; // Indica que não encontrou
}

int adiciona_valor(int L[], int *tamanho){

    int valor;
    int posicao = *tamanho;

    //verifica se esta cheio
    if(*tamanho == 10){
        printf("Vetor esta cheio!");
        return 0;

    } else {
        printf("Qual valor quer adicionar: ");
        scanf("%d", &valor);

        for(int i = 0; i< *tamanho; i++ ){

            if(valor == L[i]){
                printf("Ja existe esse valor!");
                return 0;

            } else if(valor < L[i] ){
                posicao = i;
                break;
            }
        }

        // Move elementos à direita para abrir espaço
        for(int j = *tamanho; j > posicao; j--){
            L[j] = L[j-1];
        }

         // Insere o valor na posição correta
        L[posicao] = valor;
        (*tamanho)++;  // Aumenta o tamanho

        printf("Valor %d inserido na posicao %d\n", valor, posicao);
        return 1;
    }
    //se nao insere o valor em ordem crescente 

    //mostra o novo vetor

    
}

int main(){
    int L[10] = {1,2,3,4,5,6,7,8,9,10};
    int tamanho = 10;  // Controla quantos elementos são válidos

    printf("Vetor original: ");
    for(int i = 0; i < tamanho; i++){  // Só mostra elementos válidos
        printf("%d ", L[i]);
    }
    printf("\n");

    remove_numero(L, &tamanho);  // Passa endereço do tamanho

    printf("Vetor apos remocao: ");
    for(int i = 0; i < tamanho; i++){  // Só mostra elementos válidos
        printf("%d ", L[i]);
    }
    printf("\n");
    printf("Tamanho atual: %d\n", tamanho);

    adiciona_valor(L, &tamanho);

    printf("\n");
    printf("Vetor apos insercao: ");
    for(int i = 0; i < tamanho; i++){  // Só mostra elementos válidos
        printf("%d ", L[i]); //bug aqui

    return 0;
    }
}
