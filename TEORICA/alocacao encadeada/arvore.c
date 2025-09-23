#include<stdio.h>
#include<stdlib.h>

typedef struct noArvore_ {
    int valor;
    struct noArvore_ * esq;
    struct noArvore_ * dir;
} noArvore;

noArvore * aloca_no(int valor) {
    noArvore * no = (noArvore*) malloc(sizeof(noArvore));
    //(*no).valor = valor;
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

void pre_ordem(noArvore * raiz){
    if(raiz == NULL)
        return;
    printf("%d\n", raiz->valor);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

void em_ordem(noArvore * raiz){
    if(raiz == NULL)
        return;
    pre_ordem(raiz->esq);
    printf("%d\n", raiz->valor);
    pre_ordem(raiz->dir);
}

void pos_ordem(noArvore * raiz){
    if(raiz == NULL)
        return;
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
    printf("%d\n", raiz->valor);
}

noArvore * insere(noArvore * raiz, noArvore * n){
    if(raiz == NULL) return n;
    if(raiz->valor > n->valor)
        raiz->esq = insere(raiz->esq, n);
    else
        raiz->dir = insere(raiz->dir, n);
    return raiz;
}

noArvore * busca(noArvore * raiz, int k){
    if(raiz == NULL || raiz->valor == k)
        return raiz;
    if(raiz->valor > k)
        return busca (raiz->esq, k);
    else
        return busca (raiz->dir, k);
}

noArvore * busca_pai(noArvore * raiz, noArvore * n){
    if(raiz == n)
        return NULL;
    
    if((raiz->esq != NULL && raiz->esq == n) ||
    (raiz->dir != NULL && raiz->dir == n))
        return raiz;
    
    if(raiz->valor > n->valor)
        return busca_pai (raiz->esq, n);
    else
        return busca_pai (raiz->dir, n);
}

noArvore * remove_raiz(noArvore * r){
    noArvore * p = r; //pai sera igual a raiz (3)
    noArvore * q;

    if (r->esq != NULL){
        noArvore * q =  r->esq; //filho a esquerda (2)
    } else{
        noArvore * q =  r; //filho a esquerda (2)
    }
   
    if (q == r){ //nao possui filhos a esquerda
            q = r->dir;
    } else{

        while(q->dir != NULL){ 
            p = q;
            q = q->dir;
        }
        
        if (p != r){
            p->dir = q->esq;
            q->esq = r->esq;
        }
        q->dir = r->dir;
   
    }

    return q;
}

noArvore * remove_no(noArvore* raiz, int valor){
    noArvore * n = busca(raiz, valor);
    printf("busca funcionou!\n");
    //getchar(); //serve para depurar e encontarr o erro no codigo!
    //getchar(); //pq coloca dois??
    if(n){
        printf("no encontrado!\n");
        //getchar();
        //getchar();
        noArvore * pai = busca_pai(raiz, n);
        printf("pai= %d\n", pai->valor);
        //getchar();
        //getchar();

        if(pai){
            printf("pai encontrado!\n");{
    /* data */
};

{
    /* data */
};
            //getchar();
            //getchar();
            if(pai->dir == n)
                pai->dir = remove_raiz(n);
            else
                pai->esq = remove_raiz(n);
        }else{
            printf("pai não encontrado!\n");
            getchar();
            getchar();
            raiz = remove_raiz(n);
        }
    }
    return raiz;
}

void imprime_busca(noArvore * raiz, int k){
    if(busca(raiz, k) == NULL)
        printf("valor %d não encontrado!\n", k);
    else
        printf("valor %d encontrado!\n", k);
}

void main(){
    noArvore * raiz = NULL;
    noArvore * no_inserir = aloca_no(10);
    raiz = insere(raiz, no_inserir);

    no_inserir = aloca_no(5);
    raiz = insere(raiz, no_inserir);

    no_inserir = aloca_no(15);
    raiz = insere(raiz, no_inserir);

    no_inserir = aloca_no(7);
    raiz = insere(raiz, no_inserir);

    imprime_busca(raiz, 15);
    imprime_busca(raiz, 17);
    
    printf("pre-ordem\n");
    pre_ordem(raiz);
    printf("\nem-ordem\n");
    em_ordem(raiz);
    printf("\npos-ordem\n");
    pos_ordem(raiz);

    raiz = remove_no(raiz, 5);

    printf("\nem-ordem\n");
    em_ordem(raiz);
}