#include <stdio.h>
#include <stdlib.h>


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

/*
Esse realiza a busca, entratanto quando se compara o busca com o busca2, se tem diferenças entre eles, em qustão de velocidade e 
eficiencia, já que o busca roda o vetor todo, e o busca2 so vai té o numero desejado, ou seja, mais eficaz(menor numeros de ifs).
*/

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
//Função de Busca Ordenada, só funciona quando o vetor está em ordem.
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

//Bem eficaz já que faz a divisão do vetor em meios e meios, para facilitar a busca do numero desejado.
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

//insere um valor no vetor, caso haja espaço para esse tipo de interação.
int inserir(REGISTRO L[], int QuantAtual, int Quant, int x){
    if(QuantAtual <= Quant){
        if(busca2(L, x, QuantAtual) == 0){
            L[QuantAtual + 1].chave = x;
            QuantAtual++;
            return QuantAtual;
        }else return 0;
    }else return -1;
}

// Remove um valor do vetor, ajustando o tamanho. Retorna o novo tamanho ou 0 se não encontrou.
int remover(REGISTRO L[], int QuantAtual, int x){
    int i, j, pos = -1;
    // Busca a posição do elemento a ser removido
    for(i = 0; i < QuantAtual; i++) {
        if(L[i].chave == x) {
            pos = i;
            break;
        }
    }
    if(pos == -1) { ;
        return 0;
    }
    // Desloca os elementos para "tapar o buraco"
    for(j = pos; j < QuantAtual - 1; j++) {
        L[j] = L[j+1];
    }
    return QuantAtual - 1;
}
    


int main(){

    REGISTRO L[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b1, b2, bo, bb, ins, rem, opcao = 10;

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
        case 5:{
            printf("Digite um numero para inserir no vetor: ");
            scanf("%d", &ins);
            ins = inserir(L,10,11,ins);
            break;
        }
        case 6:{
            printf("Digite um numero para ser removido do vetor: ");
            scanf("%d", &rem);
            break;
        }

         default:
            opcao = menu();   
            break;
        
    }   

}

