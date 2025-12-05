#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o vetor
void imprimirVetor(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Implementação do Bubble Sort
void bubbleSort(int arr[], int tamanho) {
    int temp;
    int houveTroca;
    
    for (int i = 0; i < tamanho - 1; i++) {
        houveTroca = 0;
        
        // Percorre o vetor comparando elementos adjacentes
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                houveTroca = 1;
            }
        }
        
        // Se não houve troca, o vetor já está ordenado
        if (houveTroca == 0) {
            break;
        }
    }
}

int main() {
    // Exemplo 1: Vetor desordenado
    int vetor1[] = {64, 34, 25, 12, 22, 11, 90};
    int tam1 = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("=== Bubble Sort - Exemplo 1 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor1, tam1);
    
    bubbleSort(vetor1, tam1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor1, tam1);
    printf("\n");
    
    // Exemplo 2: Vetor em ordem decrescente (pior caso)
    int vetor2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tam2 = sizeof(vetor2) / sizeof(vetor2[0]);
    
    printf("=== Bubble Sort - Exemplo 2 (Pior Caso) ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor2, tam2);
    
    bubbleSort(vetor2, tam2);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor2, tam2);
    printf("\n");
    
    // Exemplo 3: Vetor já ordenado (melhor caso)
    int vetor3[] = {1, 2, 3, 4, 5};
    int tam3 = sizeof(vetor3) / sizeof(vetor3[0]);
    
    printf("=== Bubble Sort - Exemplo 3 (Melhor Caso) ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor3, tam3);
    
    bubbleSort(vetor3, tam3);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor3, tam3);
    
    return 0;
}
