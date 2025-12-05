#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o vetor
void imprimirVetor(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para mesclar dois subvetores ordenados
void merge(int arr[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;  // Tamanho do subvetor esquerdo
    int n2 = direita - meio;        // Tamanho do subvetor direito
    
    // Criar arrays temporários
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    if (L == NULL || R == NULL) {
        fprintf(stderr, "Erro ao alocar memória temporária\n");
        exit(1);
    }
    
    // Copiar dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];
    
    // Mesclar os arrays temporários de volta em arr[esquerda..direita]
    int i = 0;    // Índice inicial do primeiro subvetor
    int j = 0;    // Índice inicial do segundo subvetor
    int k = esquerda; // Índice inicial do subvetor mesclado
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Liberar memória temporária
    free(L);
    free(R);
}

// Função principal do Merge Sort
void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        // Encontra o ponto médio
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Ordena a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);
        
        // Mescla as duas metades ordenadas
        merge(arr, esquerda, meio, direita);
    }
}

int main() {
    // Exemplo 1: Vetor desordenado
    int vetor1[] = {12, 11, 13, 5, 6, 7};
    int tam1 = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("=== Merge Sort - Exemplo 1 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor1, tam1);
    
    mergeSort(vetor1, 0, tam1 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor1, tam1);
    printf("\n");
    
    // Exemplo 2: Vetor maior
    int vetor2[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 33, 17};
    int tam2 = sizeof(vetor2) / sizeof(vetor2[0]);
    
    printf("=== Merge Sort - Exemplo 2 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor2, tam2);
    
    mergeSort(vetor2, 0, tam2 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor2, tam2);
    printf("\n");
    
    // Exemplo 3: Vetor em ordem decrescente (pior caso para alguns algoritmos)
    int vetor3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tam3 = sizeof(vetor3) / sizeof(vetor3[0]);
    
    printf("=== Merge Sort - Exemplo 3 ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor3, tam3);
    
    mergeSort(vetor3, 0, tam3 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor3, tam3);
    printf("\n");
    
    // Exemplo 4: Vetor com elementos repetidos
    int vetor4[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int tam4 = sizeof(vetor4) / sizeof(vetor4[0]);
    
    printf("=== Merge Sort - Exemplo 4 (com repetidos) ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor4, tam4);
    
    mergeSort(vetor4, 0, tam4 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor4, tam4);
    printf("\n");
    
    // Exemplo 5: Vetor já ordenado (melhor caso para alguns algoritmos)
    int vetor5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tam5 = sizeof(vetor5) / sizeof(vetor5[0]);
    
    printf("=== Merge Sort - Exemplo 5 (já ordenado) ===\n");
    printf("Vetor original: ");
    imprimirVetor(vetor5, tam5);
    
    mergeSort(vetor5, 0, tam5 - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor5, tam5);
    
    return 0;
}
