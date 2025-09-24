#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
    int chave;
    int valor;
    struct lista *prox;
    struct lista *ant;
}no;

void buscaLista(no *ptlista, no **ant, no **pont, int x){
    *ant = ptlista; //ant aponta pro ptlista
    *pont = NULL; //pont e null
    no *ptr = ptlista->prox;; //ptr marca o primeiro no valido da lsita
    
    while(ptr != ptlista){ //enquanto eu nao olhar novamente para o comeco percorro a lista
        if(ptr->chave < x){ //se a chave atual for menor que a que quero inserir anda pra frente na lista
            *ant = ptr; //ant aponta pro ptr
            ptr = ptr->prox; //ptr aponta pro proximo
        }else if(ptr->chave == x){ //se eu encontrar o elemento na lista
            *pont = ptr; //pont guarda o elemento encontrado
            break; //sai do loop
        }else{
            break; //sai do loop
        }
    }
}   

int insereLista(no *ptlista, no *novoNo){
    no *ant;
    no *pont;

    buscaLista(ptlista, &ant, &pont, novoNo->chave); //chama funcao de busca para posicionar os ponteiros

    if(pont == NULL){ //caso o no a inserir nao for encontrado posso inserir ele
        ant->prox->ant = novoNo; //o no de ant aponta corretamente
        novoNo->prox = ant->prox; //o no a inserir aponta pro proximo do ant
        novoNo->ant = ant; //o ant do do a inserir aponta pro ant
        ant->prox = novoNo; //proximo do ant e o novo no

        return 0; //retorna 0 para confirmar insercao
    }
    return -1; //retorna -1 caso nao seja possivel inserir (elmento ja existe na lista)
}

no *removeLista(no *ptlista, int x){
    no *ant;
    no *pont;
    no *retorno = NULL;
    buscaLista(ptlista, &ant, &pont, x); //aponta os ponteiros corretamente

    if(pont != NULL){ //se o pont encontrou oq remover
        retorno = pont; //guardo o no removido na varaivel de retorno
        ant->prox = pont->prox; //atualizo o ponteiro do anterior pro proximo do no removido
        pont->prox->ant = ant; //atualiza o ponteiro do anterior do proximo elemento do no removido para o ant
    }
    return retorno; //retorna NULL ou o elemento removido
}

void imprimeLista(no *ptlista){
    no *aux = ptlista->prox; //posiciona o aux corretamente no primeiro elemento da lista
    if(aux == ptlista){
        printf("\nLista Vazia\n");
    }
    while(aux != ptlista){ //equanto eu percorrer a lista completamente
        printf("\nChave: %d Valor: %d \n",aux->chave,aux->valor); //imprime valor e chave
        aux = aux->prox; //aponta para o proximo elemento
    }
}

void limpaLista(no *ptlista){
    no *aux = ptlista->prox; //posiciona o aux no primeiro elemento da lista

    while(aux != ptlista){ //enquanto eu nao percorrer toda a lista
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
    ptlista->prox = ptlista; //lista comeca com ptlista apontando para ele mesmo
    ptlista->ant = ptlista; //lista comeca com ptlista apontando para ele mesmo

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