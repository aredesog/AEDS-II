#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o vetor
void imprimirVetor(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para trocar dois elementos
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para "descer" um nó na heap (heapify)
// Garante que a subárvore com raiz no índice i seja um max-heap
void heapify(int arr[], int tamanho, int i) {
    int maior = i;           // Inicializa o maior como raiz
    int esquerda = 2 * i + 1; // Filho esquerdo
    int direita = 2 * i + 2;  // Filho direito
    
    // Se o filho esquerdo existe e é maior que a raiz
    if (esquerda < tamanho && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }
    
    // Se o filho direito existe e é maior que o maior até agora
    if (direita < tamanho && arr[direita] > arr[maior]) {
        maior = direita;
    }
    
    // Se o maior não é a raiz
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        
        // Recursivamente heapify a subárvore afetada
        heapify(arr, tamanho, maior);
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int tamanho) {
    // 1. Construir max-heap (reorganizar o array)
    // Começa do último nó não-folha e vai até a raiz
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(arr, tamanho, i);
    }
    
    // 2. Extrair elementos do heap um por um
    for (int i = tamanho - 1; i > 0; i--) {
        // Move a raiz atual (maior elemento) para o final
        trocar(&arr[0], &arr[i]);
        
        // Chama heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

int main() {
    // Exemplo 1: Vetor desordenado
    int vetor1[] = {12, 11, 13, 5, 6, 7};
    int tam1 = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("=== Heap Sort - Exemplo 1 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor1, tam1);
    
    heapSort(vetor1, tam1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor1, tam1);
    printf("\n");
    
    // Exemplo 2: Vetor maior
    int vetor2[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 33, 17};
    int tam2 = sizeof(vetor2) / sizeof(vetor2[0]);
    
    printf("=== Heap Sort - Exemplo 2 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor2, tam2);
    
    heapSort(vetor2, tam2);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor2, tam2);
    printf("\n");
    
    // Exemplo 3: Vetor em ordem decrescente
    int vetor3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tam3 = sizeof(vetor3) / sizeof(vetor3[0]);
    
    printf("=== Heap Sort - Exemplo 3 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor3, tam3);
    
    heapSort(vetor3, tam3);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor3, tam3);
    printf("\n");
    
    // Exemplo 4: Vetor com elementos repetidos
    int vetor4[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int tam4 = sizeof(vetor4) / sizeof(vetor4[0]);
    
    printf("=== Heap Sort - Exemplo 4 (com repetidos) ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor4, tam4);
    
    heapSort(vetor4, tam4);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor4, tam4);
    
    return 0;
}
