#include<stdio.h> 
#include<stdlib.h> 
#include "arvore.h"
  
struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
    int altura;
};

// Obtem a altura da AVL
int altura(struct Node *N) { 
    if (N == NULL) {
        return 0; 
    }
    return N->altura; 
} 
  
// Obtem o máximo entre dois inteiros
int max(int a, int b)  { 
    if (a < b) {
        return (b);
    } 
    return (a); 
} 
  
/* Cria um novo nó com apontadores esquerda e direita nulos */
struct Node* newNode(int valor) { 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->valor     = valor; 
    node->esquerda  = NULL; 
    node->direita   = NULL; 
    node->altura    = 1;  // Novo nó é adicionado como folha
    return(node); 
} 
  
// Faz a rotação a direita na raiz y
struct Node *direitaRotate(struct Node *y) { 
    struct Node *x = y->esquerda; 
    struct Node *T2 = x->direita; 
  
    // Realiza a rotação
    x->direita = y; 
    y->esquerda = T2; 
  
    // Atualiza as alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1; 
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1; 
  
    // Retorna a nova raiz
    return x; 
} 
  
// Faz a rotação a esquerda na raiz x
struct Node *esquerdaRotate(struct Node *x) { 
    struct Node *y = x->direita; 
    struct Node *T2 = y->esquerda;  // CORREÇÃO: T2 é a subárvore esquerda de y
    
    y->esquerda = x; 
    x->direita = T2; 
  
    // Atualiza as alturas
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1; 
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1; 
  
    return y; 
} 
  
// Obtem o fator de balanceamento para o nó N
int balanceamento(struct Node *N) { 
    if (N == NULL) {
        return 0; 
    }
    return (altura(N->esquerda) - altura(N->direita)); 
} 
  
// Função recursiva para inserir um novo item na árvore com raiz
// *Node e retorna a nova raiz da subárvore
struct Node* inserir(struct Node* node, int valor) { 
    /* 1.  Realiza a inserção normal de árvore binária */
    if (node == NULL) {
        return(newNode(valor)); 
    }
  
    if (valor < node->valor) {
        node->esquerda  = inserir(node->esquerda, valor); 
    } else if (valor > node->valor){ 
        node->direita = inserir(node->direita, valor); 
    } else { 
        // Valores duplicados não são permitidos na AVL
        return node; 
    }

    /* 2. Atualiza a altura de seu antecessor */
    node->altura = 1 + max(altura(node->esquerda), 
                        altura(node->direita)); 
  
    /* 3. Obtem o fator de balanceamento da raiz 
    para observar se a árvore continua balanceada */
    int balance = balanceamento(node); 
  
    // Se a árvore está desbalanceada, então existem quatro casos possíveis
  
    /* Caso esquerda esquerda
        T1, T2, T3 e T4 são sub-árvores.
          z                                      y 
         / \                                   /   \
        y   T4     Rotação direita (z)        x      z
       / \          - - - - - - - - ->      /  \    /  \ 
      x   T3                               T1  T2  T3  T4
     / \
    T1   T2                                              */
    if (balance > 1 && valor < node->esquerda->valor) {
        return direitaRotate(node); 
    }
  
    /* Caso direita direita
      z                                y
     /  \                            /   \ 
    T1   y   Rotação esquerda (z)   z      x
        /  \   - - - - - - - ->    / \    / \
       T2   x                     T1  T2 T3  T4
           / \
         T3  T4                                  */
    if (balance < -1 && valor > node->direita->valor) {
        return esquerdaRotate(node); 
    }

    /* Caso esquerda direita
         z                               z                              x
        / \                            /   \                           /  \ 
       y   T4  Rotação esquerda (y)   x    T4  Rotação direita (z)   y      z
      / \      - - - - - - - - ->    /  \       - - - - - - - ->    / \    / \
    T1   x                          y    T3                       T1  T2 T3  T4
        / \                        / \
      T2   T3                    T1   T2                                     */
    if (balance > 1 && valor > node->esquerda->valor) { 
        node->esquerda =  esquerdaRotate(node->esquerda); 
        return direitaRotate(node); 
    } 
  
    /* Caso direita esquerda
       z                            z                            x
      / \                          / \                          /  \ 
    T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
        / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
       x   T4                      T2   y                  T1  T2  T3  T4
      / \                              /  \
    T2   T3                           T3   T4                             */
    if (balance < -1 && valor < node->direita->valor) { 
        node->direita = direitaRotate(node->direita); 
        return esquerdaRotate(node); 
    } 
  
    /* retorna o ponteiro (não-atualizado) para a raiz */
    return node; 
} 
  
// Retorna o nó com o menor valor na árvore (usado na remoção)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->esquerda != NULL)
        current = current->esquerda;
    return current;
}

// Remove um valor da AVL e retorna a nova raiz da subárvore
struct Node* remover(struct Node* root, int valor) {
    if (root == NULL)
        return root;

    // 1) BST delete padrão
    if (valor < root->valor) {
        root->esquerda = remover(root->esquerda, valor);
    } else if (valor > root->valor) {
        root->direita = remover(root->direita, valor);
    } else {
        // nó com um ou nenhum filho
        if (root->esquerda == NULL || root->direita == NULL) {
            struct Node* temp = root->esquerda ? root->esquerda : root->direita;
            if (temp == NULL) {
                // sem filhos
                temp = root;
                root = NULL;
                free(temp);
            } else {
                // um filho: copia conteúdo e libera temp
                *root = *temp;
                free(temp);
            }
        } else {
            // nó com dois filhos: pega o sucessor in-order (menor da direita)
            struct Node* temp = minValueNode(root->direita);
            root->valor = temp->valor;
            root->direita = remover(root->direita, temp->valor);
        }
    }

    // Se a árvore tinha apenas um nó
    if (root == NULL)
        return root;

    // 2) Atualiza altura
    root->altura = 1 + max(altura(root->esquerda), altura(root->direita));

    // 3) Verifica balanceamento e rotaciona se necessário
    int balance = balanceamento(root);

    // esquerda esquerda
    if (balance > 1 && balanceamento(root->esquerda) >= 0)
        return direitaRotate(root);

    // esquerda direita
    if (balance > 1 && balanceamento(root->esquerda) < 0) {
        root->esquerda = esquerdaRotate(root->esquerda);
        return direitaRotate(root);
    }

    // direita direita
    if (balance < -1 && balanceamento(root->direita) <= 0)
        return esquerdaRotate(root);

    // direita esquerda
    if (balance < -1 && balanceamento(root->direita) > 0) {
        root->direita = direitaRotate(root->direita);
        return esquerdaRotate(root);
    }

    return root;
}

// Imprime os nós em ordem
void inOrder(struct Node *raiz) { 
    if(raiz != NULL) { 
        inOrder(raiz->esquerda); 
        printf("%d ", raiz->valor); 
        inOrder(raiz->direita); 
    } 
} 
  
/* Driver program to test above function*/
int main() { 
  struct Node *raiz = NULL; 
  
  /* Constructing tree given in the above figure */
  raiz = inserir(raiz, 10); 
  raiz = inserir(raiz, 20); 
  raiz = inserir(raiz, 30); 
  raiz = inserir(raiz, 40); 
  raiz = inserir(raiz, 50); 
  raiz = inserir(raiz, 25); 
  
  /* A árvore AVL construída será
            30 
           /  \ 
         20   40 
        /  \    \ 
       10  25    50 
  
  A saida correta em pre-ordem é 30 20 10 25 40 50 */
  
  printf("Os elementos da árvore, em ordem, são \n"); 
  inOrder(raiz); 
  printf("\n");

  return 0; 
}