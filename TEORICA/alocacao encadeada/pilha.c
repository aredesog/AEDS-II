#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int chave;
    int valor;
    struct pilha *prox;
}no;

void inserePilha(no **topo, no *no){
    no->prox = *topo; //aponta o novo no para o primeiro item da pilha
    *topo = no; //atualiza o topo para o novo no
}

no *removePilha(no **topo){
    no *retorno = *topo; //variavel de retorno
    *topo = (*topo)->prox; //o topo aponta para o proximo elemento

    return retorno; //retorno o elemento removido
}

void limpaPilha(no **topo){
    while(*topo != NULL){ //enquanto existir elementos na pilha percorre a pilha
        no *aux = *topo; //no auxiliar aponta para topo da pilha
        *topo = (*topo)->prox; //topo a ponta para proximo elemento
        free(aux); //limpa o elemento anterior da memoria
    }
}

no *alocaPilha(int x){
    no *novoNo = malloc(sizeof(no)); //aloca um novo no na memoria
    if(novoNo == NULL){ //verificacao de erro de alocacao de memoria
        printf("\nErro ao alocar memoria\n");
        return NULL; //retorna NULL indicando erro
    }
    novoNo->chave = x; //atribui x a chave do novo no
    novoNo->valor = x * 10; //atribui um valor
    novoNo->prox = NULL; //coloca o proximo do novo no para nulo

    return novoNo; //retorna o endereco de memoria do novo no
}

void imprimePilha(no *topo){
    printf("\nConteudo da pilha:\n"); 
    while(topo != NULL){ //enquanto existir itens na pilha percorre a pilha
        printf("\nChave: %d Valor: %d\n",topo->chave, topo->valor); //imprime a chave e valor do elemento atual
        topo = topo->prox; //passa para o elemento seguinte da pilha
    }
}

int main(){
    no *topo = NULL; //topo comeca NULL pois nao possui itens na pilha

    no *no1 = alocaPilha(1); //Aloca nos de teste da pilha
    inserePilha(&topo, no1);

    no *no2 = alocaPilha(2);
    inserePilha(&topo, no2);

    no *no3 = alocaPilha(3);
    inserePilha(&topo, no3);
    
    no *no4 = alocaPilha(4);
    inserePilha(&topo, no4);

    no *no5 = alocaPilha(5);
    inserePilha(&topo, no5);

    imprimePilha(topo); //imprime a pilha

    no *noRemovido1 = removePilha(&topo); //remove 2 nos para teste
    no *noRemovido2 = removePilha(&topo);

    imprimePilha(topo); //imprime para visualizar remocao

    limpaPilha(&topo); //limpa a pilha da memoria e os elementos removidos também
    free(noRemovido1);
    free(noRemovido2);
    
    if(topo == NULL){ //testa se o topo de fato ficou nulo apos remover todo elementos da pilha
        printf("\nTopo NULL\n");
    }

    return 0;
}

