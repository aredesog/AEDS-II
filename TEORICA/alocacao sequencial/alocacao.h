#ifndef ALOCACAO_H
#define ALOCACAO_H

typedef struct no{
    int chave;
    int valor;
}No;

typedef struct no2{
    int chave;
    int valor;
}pilha;

typedef struct no3{
    int chave;
    int valor;
}fila;

extern No L[5];
extern No L1[6];
extern pilha p[6];
extern fila fi[6];
extern int n;
extern int n2;
extern int m;
extern int topo; //variavel topo da pilha
extern int f; //variaveldo inico da fila
extern int r; //variavel de fim de fila

int busca1(int x);
int busca2(int x);
int buscaOrd(int x);
int buscaBin(int x);
int insere(No no);
No *removeLista(int x);
int inserePilha(pilha no);
pilha *removePilha();
int insereFila(fila no);
fila *removeFila();

#endif