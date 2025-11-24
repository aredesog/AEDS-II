#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int chave;
    int valor;
    struct arvore *dir;
    struct arvore *esq;
}no;

no *buscaArvore(no *raiz, int x){
    if(raiz == NULL || raiz->chave == x){ // se a raiz for vazia == arvore vazia
        return raiz;
    }

    if(x < raiz->chave){
        return buscaArvore(raiz->esq, x); //menor p esquerda
    }else{
        return buscaArvore(raiz->dir, x); // maior para direita
    }
}

no *buscaPai(no *raiz, no *n){
    if(raiz == NULL || raiz->chave == n->chave){
        return NULL;
    }

    if(raiz->esq != NULL && raiz->esq == n){
        return raiz;
    }
    if(raiz->dir != NULL && raiz->dir == n){
        return raiz;
    }

    if (n->chave < raiz->chave){
        return buscaPai(raiz->esq, n);
    }else{
        return buscaPai(raiz->dir, n);
    }
}

no *removeRaiz(no *raiz){
    if(raiz->dir == NULL && raiz->esq == NULL){
        return NULL;
    }else if(raiz->esq == NULL){
        return raiz->dir;
    }else if(raiz->dir == NULL){
        return raiz->esq;
    }else{
         no *aux = raiz->esq;
         no *aux2 = NULL;

         while(aux->dir != NULL){
            aux2 = aux;
            aux = aux->dir;
         }

        if(aux2 != NULL){
            aux2->dir = aux->esq;
        }

        aux->dir = raiz->dir;
        aux->esq = raiz->esq;

        free(raiz);
        return aux;
    }
}

no *removeNo(no *raiz, int x){ ///PSEUDO CODIGO SEM SOLUCAO AINDA
    no *n = buscaArvore(raiz,x);
    if(n){
        no *pai = buscaPai(raiz, n);
        if(pai){
            if(pai->dir == n){
                pai->dir = removeRaiz(n);
            }else{
                pai->esq = removeRaiz(n);
            }
        }else{
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}

no *alocaNo(int x){
    no *raiz = malloc(sizeof(no)); //aloca um no da raiz

    if(raiz == NULL){ //se nao alocar a raiz direito retorna NULL
        printf("\nErro ao alocar memoria\n");
        return NULL;
    }

    raiz->chave = x; //atribui a chave
    raiz->valor = x * 10; //atribui o valor
    raiz->esq = NULL; //esquerda nao tem elemento
    raiz->dir = NULL; //direita nao tem elemento

    return raiz; //retorna a raiz criada
}

no *insereArvore(no *raiz, int chave){
    if(raiz == NULL){ //se a raiz for nula eu insiro na posicao
        return alocaNo(chave);
    }

    if(chave < raiz->chave){ //se a chave for menor ando pela esquerda
        raiz->esq = insereArvore(raiz->esq, chave);
    }else if(chave > raiz->chave){ //se a chave for maior anda pela direita
        raiz->dir = insereArvore(raiz->dir, chave);
    }else{ //se nao for maior ou menor a chave ja existe na arvore
        printf("\nChave ja existente na arvore",chave);
    }

    return raiz; //retorna a propria raiz
}

void visita(no *raiz){
    printf("\nChave: %d ",raiz->chave);
    free(raiz);
}

void preOrdem(no *raiz){ //imprime a arvore em pre ordem
    if(raiz != NULL){
        printf("\nChave: %d",raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(no *raiz){ //imprime a arvora em ordem
    if(raiz != NULL){
        emOrdem(raiz->esq);
        printf("\nChave: %d",raiz->chave);
        emOrdem(raiz->dir);
    }
}

void posOrdem(no *raiz){ //imprime a arvore em pos ordem
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        visita(raiz);
    }
}

int main(){
    no *raiz = NULL;

    raiz = insereArvore(raiz, 30);
    raiz = insereArvore(raiz, 25);
    raiz = insereArvore(raiz, 35);
    raiz = insereArvore(raiz, 24);
    raiz = insereArvore(raiz, 27);
    raiz = insereArvore(raiz, 34);
    raiz = insereArvore(raiz, 38);

    printf("\nPre ordem:\n");
    preOrdem(raiz);

    printf("\nEm ordem:\n");
    emOrdem(raiz);

    printf("\nPos ordem:\n");
    posOrdem(raiz);

    raiz = NULL;

    return 0;
}