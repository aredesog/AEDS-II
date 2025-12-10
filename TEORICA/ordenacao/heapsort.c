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
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    printf("Vetor original: ");
    imprimirVetor(vetor, tamanho);
    
    heapSort(vetor, tamanho);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor, tamanho);
    
    return 0;
}
