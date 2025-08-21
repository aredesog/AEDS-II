#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
    int chave;
}REGISTRO;

int busca (int x, REGISTRO L[], int n){
 int i = 1 ;
 int busca = 0;

    while(i<=n){
        if(L[i].chave == x){
            busca = i;
            i = n + 1;
        } else {
            i = n + 1;
        }
    }
}

int busca2(REGISTRO L[], int x, int n){
    int i = 0;
    L[n + 1].chave = x;
    while(L[i].chave != x){
        i++;
    }

    if (i != n + 1) {
        return i + 1;   
    } else {
        return 0;       
    }
}
//Função de Busca Ordenada
int buscaOrd(REGISTRO L[], int x, int n){
    int i = 0;
    L[n + 1].chave = x;
    while(L[i].chave < x){
        i++;
    }

    if (i == n + 1 || L[i].chave != x) {
        return 0;   
    } else {
        return i + 1;       
    }
}

int buscaBinaria(REGISTRO L[], int x, int n){
    int inf = 0,
        sup = n,
        buscaBin = 0;
    while(inf <= sup){
        int meio = (inf + sup)/2;
        if(L[meio].chave == x){
            buscaBin = meio;
            break;
        }else if(L[meio].chave < x){
            inf = meio + 1;
        }else sup = meio - 1;
    }
    return buscaBin + 1;
} 
    


int main(){

    REGISTRO L[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b1, b2, bo, bb, opcao = 0;

    switch (opcao)
    {
        case 1: {
            printf("Digite um numero para buscar pela função busca 1:\n ");
            scanf("%d", &b1); 
            b1 = busca(L,b1,10);
        break;
        }

        case 2:{
            printf("Digite um numero para buscar pela função busca 2:\n ");
            scanf("%d", &b2); 
            b2 = busca2(L,b2,10);
        break;
        }

        case 3:{
            printf("Digite um numero para buscar pela função busca 3:\n ");
            scanf("%d", &bo); 
            bo = buscaOrd(L,bo,10);
        break;
        }

        case 4:{
            printf("Digite um numero para buscar pela função busca 4:\n ");
            scanf("%d", &bo);
            bb = buscaBinaria(L, bb, 10);
        break;
        }
        
        default:
            printf("Opção inválida.\n");
            break;
        scanf("%d", &opcao);
    }   

}

