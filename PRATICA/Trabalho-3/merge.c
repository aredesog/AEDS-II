#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tp3.h"

// Função auxiliar para mesclar dois subarrays no Merge Sort
void merge(jogador vetor[], int tamanho, int *comparacao, int *troca, int inicio, int meio, int fim, size_t *memoria_total) {
    int tamanho_esq = meio - inicio + 1; // Tamanho do subarray esquerdo
    int tamanho_dir = fim - meio;        // Tamanho do subarray direito

    // Alocação dinâmica para subarrays temporários
    jogador *vetor_esquerdo = malloc(tamanho_esq * sizeof(jogador));
    if (vetor_esquerdo) *memoria_total += tamanho_esq * sizeof(jogador);

    jogador *vetor_direito = malloc(tamanho_dir * sizeof(jogador));
    if (vetor_direito) *memoria_total += tamanho_dir * sizeof(jogador);

    // Copia os elementos para os subarrays temporários
    for (int idx_esq = 0; idx_esq < tamanho_esq; idx_esq++) 
        vetor_esquerdo[idx_esq] = vetor[inicio + idx_esq];
    for (int idx_dir = 0; idx_dir < tamanho_dir; idx_dir++) 
        vetor_direito[idx_dir] = vetor[meio + 1 + idx_dir];

    // Mescla os subarrays ordenados de volta no array principal
    int idx_esq = 0, idx_dir = 0, idx_atual = inicio;
    while (idx_esq < tamanho_esq && idx_dir < tamanho_dir) {
        (*comparacao)++; // Incrementa o contador de comparações
        if (strcmp(vetor_esquerdo[idx_esq].nome, vetor_direito[idx_dir].nome) <= 0) {
            vetor[idx_atual++] = vetor_esquerdo[idx_esq++];
        } else {
            vetor[idx_atual++] = vetor_direito[idx_dir++];
        }
        (*troca)++; // Incrementa o contador de trocas
    }

    // Copia os elementos restantes do subarray esquerdo, se houver
    while (idx_esq < tamanho_esq) {
        vetor[idx_atual++] = vetor_esquerdo[idx_esq++];
        (*troca)++;
    }

    // Copia os elementos restantes do subarray direito, se houver
    while (idx_dir < tamanho_dir) {
        vetor[idx_atual++] = vetor_direito[idx_dir++];
        (*troca)++;
    }

    // Libera a memória alocada para os subarrays temporários
    free(vetor_esquerdo);
    free(vetor_direito);
}

// Implementação do algoritmo Merge Sort
void mergeSort(jogador vetor[], int tamanho, int *comparacao, int *troca, int inicio, int fim, size_t *memoria_total) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2; // Calcula o índice do meio

        // Recursivamente divide e ordena os subarrays
        mergeSort(vetor, tamanho, comparacao, troca, inicio, meio, memoria_total);
        mergeSort(vetor, tamanho, comparacao, troca, meio + 1, fim, memoria_total);

        // Mescla os subarrays ordenados
        merge(vetor, tamanho, comparacao, troca, inicio, meio, fim, memoria_total);
    }
}