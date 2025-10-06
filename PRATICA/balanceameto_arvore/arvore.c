#include <stdio.h>
#include <stdlib.h>
//#include "arvore.h"
 

struct node {
    int valor;
    struct node *esquerda, *direita;
};

// Cria um novo nó na árvore
struct node* novo_no(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->valor = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}
 
// Inserir novo nó com determinado
// valor na árvore binária
struct node* inserir(struct node* node, int valor) {
    // Se a árvore é vazia, então cria um novo nó
    if (node == NULL) {
        return novo_no(valor);
    }
 
    // Caso contrário, faz uma busca pelo local adequado de inserção
    if (valor < node->valor) {
        node->esquerda = inserir(node->esquerda, valor);
    } else if (valor > node->valor) {
        node->direita = inserir(node->direita, valor);
    }
    
    // Retorna o ponteiro para o nó
    return node;
}
 
// Procura por um valor na árvore
struct node* buscar(struct node* root, int valor) {
    // Caso base - a raiz é vazia ou o valor está na raiz
    if (root == NULL || root->valor == valor) {
        return root;
    }

    // Valor é maior que a raiz
    if (root->valor > valor) {
        return buscar(root->direita, valor);
    }

    // Valor é menor que a raiz
    return buscar(root->esquerda, valor);
}

struct node* remove_raiz(struct node *root){

    struct node *p = root;
    struct node *q = p->esquerda;

    if(root != NULL){
        
        //1° descer uma para a esquerda e tudo para a direita para achar o numero mais proximo para ser raiz

        while(q->direita != NULL){
            p = q;
            q = q->direita;
        }
        //achado

        //2° passo -> trocar os valores da raiz com o no achado/nova raiz

        root->valor = q->valor;
        
        //feito
        //excluir a antiga raiz
        //p->direita = NULL;
        //p = root; // retorna o pai a raiz para repetir o ciclo
        //q = root->esquerda; //retorna o filho ao local de origem
    }else {
        printf("NAO EXISTE ARVORE");
        return NULL;
    }

    if(p == root){
        // q é filho direto da raiz
        root->esquerda = q->esquerda;
    } else {
        // q não é filho direto da raiz  
        p->direita = q->esquerda;
    }

    free(q); 
    return root;

}

void preOrdem (struct node* raiz) { // função rescursiva
    if (raiz == NULL){
        return;
    }
    printf("%d\n", raiz->valor);
    preOrdem(raiz->esquerda);// função rescursiva
    preOrdem(raiz->direita);// função rescursiva
}

void emOrdem (struct node* raiz) {
    if (raiz == NULL){
        return;
    }
    emOrdem(raiz->esquerda);// função rescursiva
    printf("%d\n", raiz->valor);
    emOrdem(raiz->direita);// função rescursiva
}

void posOrdem (struct node* raiz) {
    if (raiz == NULL){
        return;
    }
    posOrdem(raiz->esquerda);// função rescursiva
    posOrdem(raiz->direita);// função rescursiva
    printf("%d\n", raiz->valor);
}

//Balanceameto de arvore

int balanceamento_arvore(struct node* raiz){

    //verifica em qual nivel esta o desbalanceameto

    //verifica qual é o tipo de desbalanceamento

    //corrige de formato cotovelo(dupla)

    //corrige de forma linha(simples)
}
 
 
int main() {
    // Define a árvore como uma estrutura vazia
    struct node* root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root,Construir uma árvore balanceada a partir da não-balanceada 50);

    // Insere outros nós
    inserir(root, 90);
    inserir(root, 20);
    inserir(root, 40);
    inserir(root, 70);
    inserir(root, 60);
    inserir(root, 85);
    inserir(root, 80);
 
    preOrdem(root);
    printf("\n");

    

    return 0;
}