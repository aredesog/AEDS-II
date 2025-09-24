#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int chave;
    int valor;
    struct lista *prox;
    struct lista *ant;
}no;

void buscaLista(no *ptlista, no **ant, no **pont, int x){
    *ant = ptlista; //ponteiro que guarda primera posicao da lista (ptlista)
    *pont = NULL; //ponteiro de retorno 
    no *ptr = ptlista->prox; //ponteiro que percorre a lista

    while(ptr != NULL){ //enquanto observar elementos validos eu percorro a lista
        if(ptr->chave < x){ //enquanto a chave for menor eu continuo procurando
            *ant = ptr; //ando para frente com os 2 ponteiros
            ptr = ptr->prox;
        }else if(ptr->chave == x){ //se eu encontrar a chave pont guarda o endereco
            *pont = ptr;
            break;
        }else{
            break;
        }
    }
}

int insereLista(no *ptlista, no *insere){
    no *ant;
    no *pont;
    
    buscaLista(ptlista, &ant, &pont, insere->chave); //busca posiciona os ponteiros

    no *aux = ant->prox; //guardo posicao da frente para manipular os ponteiros internos

    if(pont == NULL){ //se pont for NULL posso inserir pois essa chave nao esta na lista
        insere->prox = aux; //manipulo os ponteiros do novo no corretamente
        insere->ant = ant;
        ant->prox = insere; //a posicao anterior olha para o novo no

        if(aux != NULL){ //caso o no a frente do novo No for um no valido ele olha para o no inserido
            aux->ant = insere;
        }
        return 0; //caso de insercao
    }
    return -1;//nao foi possivel inserir
}

no *removeLista(no *ptlista, int x){
    no *ant;
    no *pont;

    buscaLista(ptlista, &ant, &pont, x); //posiciona os ponteiros corretamente

    if(pont != NULL){ //se pont nao for nulo encontrei oque remover
        no *aux = pont->prox; //olho para terceira posicao
        ant->prox = aux; //manipulo pos ponteiros corretamente
        if(aux != NULL){ //se a 3 posicao for valida altero ela para olhar para a primeira posicao
            aux->ant = ant;
        }
        return pont; //retorna pont no caso de remocao
    }
    return NULL; //retorna NULL caso x nao esteja na lista
}

void imprimeLista(no *ptlista){
    no *aux = ptlista->prox; //posiciona o aux corretamente no primeiro elemento da lista
    if(aux == NULL){
        printf("\nLista Vazia\n");
    }
    while(aux != NULL){ //enquanto existir itens na lista eu percorro
        printf("\nChave: %d Valor: %d \n",aux->chave,aux->valor); //imprime valor e chave
        aux = aux->prox; //aponta para o proximo elemento
    }
}

void limpaLista(no *ptlista){
    no *aux = ptlista->prox; //posiciona o aux no primeiro elemento da lista

    while(aux != NULL){ //enquanto eu nao percorrer toda a lista
        no *aux2 = aux; //aux 2 aponta para aux
        aux = aux->prox; //aux aponta para o proximo elemento
        free(aux2); //limpo o primeiro elemento da memoria
        printf("\nLimpou\n"); //mensagem de teste
    }

    free(ptlista); //limpa o ptlista apos percorrer toda a lista
    printf("\nLimpou ptlista\n");
}

no *alocaNo(int x){
    no *novoNo = malloc(sizeof(no)); //aloca um novoNo na memoria

    if(novoNo == NULL){ //caso ocorra erro ao alocar memoria uma mensagem e exibida
        printf("\nErro ao alocar memoria\n");
        return NULL; //retorna NULL indicando erro
    }

    novoNo->chave = x; //atribui o x para a chave dentro do no
    novoNo->valor = x *10; //atribui o valor 
    novoNo->prox = NULL; //proximo e nulo
    novoNo->ant = NULL; //anterior e nulo

    return novoNo; //retorna o no criado
}

int main(){
    no *ptlista = malloc(sizeof(no)); //cria o ptlista
    ptlista->prox = NULL; //lista comeca com ptlista apontando para ele mesmo
    ptlista->ant = NULL; //lista comeca com ptlista apontando para ele mesmo

    no *no1 = alocaNo(1); //alocando nos para teste
    insereLista(ptlista, no1); //teste de insercoes

    no *no2 = alocaNo(5);
    insereLista(ptlista, no2);

    no *no3 = alocaNo(3);
    insereLista(ptlista, no3);

    no *no4 = alocaNo(2);   
    insereLista(ptlista, no4);

    no *no5 = alocaNo(4);
    insereLista(ptlista, no5);

    imprimeLista(ptlista); //imprime a lista para visualizar insercao

    printf("\nRemoveu\n");
    no *removido1 = removeLista(ptlista, 5); //teste de remocao nas extremidades e no meio
    no *removido2 = removeLista(ptlista, 3);
    no *removido3 = removeLista(ptlista, 1);

    imprimeLista(ptlista); //imprime a lista para visualizar remocao

    no *removido4 = removeLista(ptlista, 2);
    no *removido5 = removeLista(ptlista, 4);

    imprimeLista(ptlista); //imprime a lista para visualizar lista vazia

    limpaLista(ptlista); //limpa a lista da memoria

    free(removido1); //limpa os nos removidos da memoria
    free(removido2);
    free(removido3);
    free(removido4);
    free(removido5);

    return 0;
}