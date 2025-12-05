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
    // Exemplo 1: Vetor desordenado (Lomuto)
    int vetor1[] = {10, 7, 8, 9, 1, 5};
    int tam1 = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("=== Quick Sort (Lomuto) - Exemplo 1 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor1, tam1);
    
    quickSort(vetor1, 0, tam1 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor1, tam1);
    printf("\n");
    
    // Exemplo 2: Vetor maior (Lomuto)
    int vetor2[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 33, 17};
    int tam2 = sizeof(vetor2) / sizeof(vetor2[0]);
    
    printf("=== Quick Sort (Lomuto) - Exemplo 2 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor2, tam2);
    
    quickSort(vetor2, 0, tam2 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor2, tam2);
    printf("\n");
    
    // Exemplo 3: Vetor com elementos repetidos (Lomuto)
    int vetor3[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int tam3 = sizeof(vetor3) / sizeof(vetor3[0]);
    
    printf("=== Quick Sort (Lomuto) - Exemplo 3 (com repetidos) ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor3, tam3);
    
    quickSort(vetor3, 0, tam3 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor3, tam3);
    printf("\n");
    
    // Exemplo 4: Usando particionamento Hoare
    int vetor4[] = {12, 11, 13, 5, 6, 7, 3, 9, 2};
    int tam4 = sizeof(vetor4) / sizeof(vetor4[0]);
    
    printf("=== Quick Sort (Hoare) - Exemplo 4 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor4, tam4);
    
    quickSortHoare(vetor4, 0, tam4 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor4, tam4);
    printf("\n");
    
    // Exemplo 5: Vetor já ordenado (pior caso para pivô fixo)
    int vetor5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tam5 = sizeof(vetor5) / sizeof(vetor5[0]);
    
    printf("=== Quick Sort (Lomuto) - Exemplo 5 (já ordenado) ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor5, tam5);
    
    quickSort(vetor5, 0, tam5 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor5, tam5);
    
    return 0;
}
