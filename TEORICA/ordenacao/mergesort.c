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
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    printf("Vetor original: ");
    imprimirVetor(vetor, tamanho);
    
    mergeSort(vetor, 0, tamanho - 1);
    
    printf("Vetor ordenado: ");
    imprimirVetor(vetor, tamanho);
    
    return 0;
}
