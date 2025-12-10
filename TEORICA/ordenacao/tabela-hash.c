#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

// Estrutura de um nó da lista encadeada (para tratamento de colisões)
typedef struct No {
    int chave;
    int valor;
    struct No* prox;
} No;

// Estrutura da tabela hash
typedef struct {
    No* tabela[TAMANHO_TABELA];
} TabelaHash;

// Função hash simples (método da divisão)
int funcaoHash(int chave) {
    return chave % TAMANHO_TABELA;
}

// Inicializa a tabela hash
void inicializarTabela(TabelaHash* th) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        th->tabela[i] = NULL;
    }
}

// Insere um elemento na tabela hash
void inserir(TabelaHash* th, int chave, int valor) {
    int indice = funcaoHash(chave);
    
    // Cria novo nó
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->valor = valor;
    novo->prox = th->tabela[indice];
    
    // Insere no início da lista
    th->tabela[indice] = novo;
}

// Busca um elemento na tabela hash
int buscar(TabelaHash* th, int chave) {
    int indice = funcaoHash(chave);
    No* atual = th->tabela[indice];
    
    // Percorre a lista encadeada
    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual->valor;
        }
        atual = atual->prox;
    }
    
    return -1; // Não encontrado
}

// Remove um elemento da tabela hash
void remover(TabelaHash* th, int chave) {
    int indice = funcaoHash(chave);
    No* atual = th->tabela[indice];
    No* anterior = NULL;
    
    // Procura o elemento
    while (atual != NULL && atual->chave != chave) {
        anterior = atual;
        atual = atual->prox;
    }
    
    // Se não encontrou
    if (atual == NULL) {
        printf("Chave %d não encontrada.\n", chave);
        return;
    }
    
    // Remove o nó
    if (anterior == NULL) {
        th->tabela[indice] = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    
    free(atual);
}


int main() {
    TabelaHash th;
    inicializarTabela(&th);
    
    // Inserindo elementos
    inserir(&th, 15, 100);
    inserir(&th, 25, 200);
    inserir(&th, 35, 300);
    inserir(&th, 5, 400);
    
    imprimirTabela(&th);
    
    // Buscando elementos
    printf("\nBuscar chave 25: %d\n", buscar(&th, 25));
    printf("Buscar chave 99: %d\n", buscar(&th, 99));
    
    // Removendo elemento
    printf("\nRemovendo chave 25...\n");
    remover(&th, 25);
    
    imprimirTabela(&th);
    
    liberarTabela(&th);
    
    return 0;
}
/*
-> Como construir uma tabela hash
    1°- Definir o tamanho da tabela (TAMANHO_TABELA).
    2°- Implementar uma função hash para mapear chaves para índices.
    3°- Criar uma estrutura para armazenar os elementos (nós da lista encadeada).
    4°- Implementar funções para inserir, buscar e remover elementos.
    5°- Tratar colisões usando listas encadeadas.
    6°- Testar a tabela hash com diferentes operações.
// */