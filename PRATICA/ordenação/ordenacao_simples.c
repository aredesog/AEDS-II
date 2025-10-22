#include<stdio.h> 
#include<stdlib.h> 
//#include "ordenacao_simples.h"


  
// Imprime um vetor de inteiros
void imprimir(int *vetor) {
    int i;
    for (i = 0; i < 50; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bubble(int *vetor, int n) {
    imprimir(vetor);
    printf("\n");
    
    int trocou;
    do {
        trocou = 0;
        for (int i = 0; i < n - 1; i++) { //varre o vetor
            if (vetor[i] > vetor[i + 1]) { //compara com o da frente

                int temp = vetor[i]; //variavel auxiliar
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                
                trocou = 1;
            }
        }
        n--; // marca aqueles que ja passou
    
        imprimir(vetor);

    } while (trocou);
}

void selection(int *vetor, int n) {
    
    imprimir(vetor);
    printf("\n");

    for(int i = 0; i < n -1; i++){
        int menor = i;
        for(int j = i;j < n; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(i != menor){
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }

    imprimir(vetor);
    }
}

void insertion(int *vetor) {
    
    imprimir(vetor);
    printf("\n");

    for (int i = 1; i < 50; i++) {
        int key = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = key;

        imprimir(vetor);
    }

    return;
}

int main() { 
  // Vetor aleatório de 50 posições
  
  int n;
  do {
    int vetor[50] = {40, 32, 24, 25,  1, 48, 38,  7, 17,  8, 42,  4, 44, 45, 27, 49, 30, 18,  6, 23,  5, 41, 33, 26, 28,  3, 37, 19, 11, 43, 39, 16, 36, 21,  9,  2, 47, 12, 50, 20, 14, 29, 35, 46, 13, 34, 31, 15, 10, 2};
    printf("\n\n\n******************** Escolha seu algoritmo *******************");
	printf("\n1.Bubble sort");
	 printf("\n2.Selection sort");
	 printf("\n3.Insertion sort");
     printf("\n0.Sair");
	 printf("\nEntre sua opção : ");
	 scanf("%d",&n);
	 switch(n) {
        case 1: bubble(vetor, 50);
			    break;
		 case 2: selection(vetor, 50);
			    break;
		 case 3: insertion(vetor);
			    break;
        case 0: exit(0);
		 	    break;
		default: printf("\n Opção errada!");
		 	    break;
		}
	} while(1);

  return 0; 
}