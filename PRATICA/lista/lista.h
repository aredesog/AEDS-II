#ifndef _H_LISTA
#define _H_LISTA

void inserir_fim(int);
void inserir_inicio(int);
void apagar(int);
void apagar_inicio(void);
void apagar_fim(void);
bool ehVazia(void);
int obter_primeiro(void);
int obter_ultimo(void);
void imprimir();
void inserirPosicao(int elemento, int posicao);
void removerPosicao(int posicao);
int obterPosicao(int posicao);

#endif // _H_LISTA