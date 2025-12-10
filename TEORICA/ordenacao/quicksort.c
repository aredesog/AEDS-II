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

// Função de particionamento (versão Lomuto)
// Escolhe o último elemento como pivô, coloca o pivô na posição correta
// e coloca todos os menores à esquerda e maiores à direita
int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];  // Escolhe o último elemento como pivô
    int i = baixo - 1;     // Índice do menor elemento
    
    for (int j = baixo; j < alto; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    
    // Coloca o pivô na posição correta
    trocar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

// Função principal do Quick Sort
void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // pi é o índice de particionamento, arr[pi] está na posição correta
        int pi = particionar(arr, baixo, alto);
        
        // Ordena recursivamente os elementos antes e depois da partição
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// Versão alternativa: particionamento Hoare (mais eficiente)
int particionarHoare(int arr[], int baixo, int alto) {
    int pivo = arr[baixo];  // Escolhe o primeiro elemento como pivô
    int i = baixo - 1;
    int j = alto + 1;
    
    while (1) {
        // Encontra elemento à esquerda que deveria estar à direita
        do {
            i++;
        } while (arr[i] < pivo);
        
        // Encontra elemento à direita que deveria estar à esquerda
        do {
            j--;
        } while (arr[j] > pivo);
        
        // Se os índices se cruzaram, retorna
        if (i >= j)
            return j;
        
        trocar(&arr[i], &arr[j]);
    }
}

// Quick Sort usando particionamento Hoare
void quickSortHoare(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionarHoare(arr, baixo, alto);
        
        quickSortHoare(arr, baixo, pi);
        quickSortHoare(arr, pi + 1, alto);
    }
}

int main() {
    int vetor[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    printf("Vetor original: ");
    imprimirVetor(vetor, tamanho);
    
    quickSort(vetor, 0, tamanho - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor, tamanho);
    
    return 0;
}
