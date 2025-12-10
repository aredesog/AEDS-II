#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// bubble sort melhor caso : COMPLEXIDADE O(n)
// bubble sort pior caso : COMPLEXIDADE O(n)^2

// Função auxiliar para trocar dois elementos
void troca(int* x, int* y){
    int aux = *x;  
    *x = *y;       
    *y = aux;      
}

void bubble_sort(int vetor[], int n){
    int i, j;
    bool trocou;  
    // Loop externo: percorre o vetor n-1 vezes
    for(int i = 0; i< n -1; i++){
        trocou = false;  
        // Loop interno: compara elementos adjacentes
        for(int j = 0; j < n - i - 1; j++){
            // Se o elemento atual for maior que o próximo, troca
            if(vetor[j] > vetor[j + 1]){
                troca(&vetor[j], &vetor[j+1]);  // realiza a troca
                trocou = true;  // marca que houve troca
                imprime_vetor(vetor, n);  // imprime o estado atual do vetor
            }
        }
        // Se não houve troca, o vetor já está ordenado
        if(!trocou) break;
    }
}

// Função para imprimir o vetor
void imprime_vetor(int vetor[], int n){
    printf("Vetor atual: ");
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n"); 
}

// Função principal
int main(){
    int vetor[5] = {5,2,22,10,1};  
    int n = 5;  
    bubble_sort(vetor, n);  // chama a função de ordenação

    return 0;  
}
/*
-> Como construir o Bubble Sort
    1°- Implementar uma função para trocar dois elementos.
    2°- Criar a função bubble_sort que recebe o vetor e seu tamanho.
    3°- Utilizar dois loops: o externo para controlar as passagens e o interno para comparar elementos adjacentes.
    4°- Adicionar uma flag para verificar se houve troca em uma passagem.
    5°- Se não houver troca, interromper o algoritmo antecipadamente.
    6°- Testar o algoritmo com diferentes conjuntos de dados.
// */