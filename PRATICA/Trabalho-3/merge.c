#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tp3.h"

// Função auxiliar para mesclar dois subarrays no Merge Sort

void merge(jogador arr[], int n, int *comparacao, int *troca, int begin, int mid, int end, size_t *memoria_total) {
    int dimL = mid - begin + 1; // Tamanho do subarray esquerdo
    int dimR = end - mid;       // Tamanho do subarray direito

    // Alocação dinâmica para subarrays temporários
    jogador *esquerda = malloc(dimL * sizeof(jogador));
    if (esquerda) *memoria_total += dimL * sizeof(jogador);

    jogador *direita = malloc(dimR * sizeof(jogador));
    if (direita) *memoria_total += dimR * sizeof(jogador);

    // Copia os elementos para os subarrays temporários
    for (int i = 0; i < dimL; i++) esquerda[i] = arr[begin + i];
    for (int j = 0; j < dimR; j++) direita[j] = arr[mid + 1 + j];

    // Mescla os subarrays ordenados de volta no array principal
    int i = 0, j = 0, k = begin;
    while (i < dimL && j < dimR) {
        (*comparacao)++; // Incrementa o contador de comparações
        if (strcmp(esquerda[i].nome, direita[j].nome) <= 0) {
            arr[k++] = esquerda[i++];
        } else {
            arr[k++] = direita[j++];
        }
        (*troca)++; // Incrementa o contador de trocas
    }

    // Copia os elementos restantes do subarray esquerdo, se houver
    while (i < dimL) {
        arr[k++] = esquerda[i++];
        (*troca)++;
    }

    // Copia os elementos restantes do subarray direito, se houver
    while (j < dimR) {
        arr[k++] = direita[j++];
        (*troca)++;
    }

    // Libera a memória alocada para os subarrays temporários
    free(esquerda);
    free(direita);
}

// Implementação do algoritmo Merge Sort
void mergeSort(jogador arr[], int n, int *comparacao, int *troca, int begin, int end, size_t *memoria_total) {
    if (begin < end) {
        int mid = begin + (end - begin) / 2; // Calcula o índice do meio

        // Recursivamente divide e ordena os subarrays
        mergeSort(arr, n, comparacao, troca, begin, mid, memoria_total);
        mergeSort(arr, n, comparacao, troca, mid + 1, end, memoria_total);

        // Mescla os subarrays ordenados
        merge(arr, n, comparacao, troca, begin, mid, end, memoria_total);
    }
}