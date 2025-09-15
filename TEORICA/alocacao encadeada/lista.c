#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int chave; //lista
    int valor; //valor a ser encontrado na lista
    struct lista *prox; //ponteiro para o proximo elemento da lista
}no;



void buscaLista(no *ptlista, int x, no **ant, no **pont){ //ponteiros para auxilio do decorrer da lista 

    no *ptr = ptlista->prox; //ponteiro que aponta para o proximo elemento da lista
    no *ant = ptlista; //ponteiro para se refenciar ao anterior
    *pont = NULL; //ponteiro para quando se achar o valor desejado na lista

    while(ptr != NULL){ //enquanto o elemento que eu preoucro nao é o proximo na lista 
        if(ptr->chave < x){ //se o elemento que eu busco é menor que atual
            *ant = ptr; //o anterior vira ptr
            ptr = ptr->prox; //ptr pula para o proximo
        } else if(ptr == x){ //se o elemento que eu busco e igual ao atual
            *pont = ptr; //o elemento foi achado e foi marcado por pont
            ptr = NULL; //ptr sai do loop
        } else { //se o elemento nao estiver na lista
            ptr = NULL; //sai do loop
        }
    }
}

int insereLista(no *ptlista, no *inserido){
    int retorno = -1; //retorna caso não dê
    no *ant; no *pont; //ponteiros de auxilio

    buscaLista(ptlista, inserido->chave, &ant, &pont); //realiza a busca do valor a ser inserido

    if(inserido->chave == NULL){ //se nao estiver lá, pode ser inserido
    inserido->prox = ant->prox; //faz o ponteiro do valor inserido ser igual ao ponteiro do anterior ao inserido, no caso o ponteiro do inserido rouba a função do anterior a ele, apontando para o valor seguinte
    ant->prox = inserido; //e o ponteiro que foi roubado aponta para o valor inserido, assim deixando ordenada a lista novamente
    retorno = 0; //retorna 0 pois a inserção foi um sucesso
    }
    return retorno; //retorna para a main
}

no *removeLista(no *ptlista, int x){
    no *retorno = NULL;//toda função de remoção começa com um ponteiro de retorno igual a nulo
    no *ant; no *pont; //ponteiros auxiliares, passado tb para funções de remoção e inserção

    if(pont != NULL){ //verifica se pode haver remoção
        ant->prox = pont->prox;
        retorno = pont; //guardo o endereço do elemento a ser removido
    }
    
    return retorno; //retorna null ou o endereço do elemento
}

void imprimeLista(no *ptlista){
    no *aux = ptlista->prox; //ponteiro auxiliar para percorrer a lista

    while(aux != NULL){ //enquanto eu olhar para um endereço valido eu imprimo ele
        printf("\nChave: %d", aux->chave); //imprime a chave do no atual
        aux = aux->prox; //aponto para o proximo
    }
}

void liberaLista(no *ptlista){
    no *aux = ptlista->prox; //ponteiro auxiliar acessa o primeiro elemento da lista

    while(aux != NULL){ //enquanto meu auxiliar olhar para um elemento valido
       no *aux2 = aux->prox; //um segundo ponteiro auxiliar olha para o proximo elemento valido
        free(aux); //limpo o primeiro elemento da memoria
        aux = aux2; //aux aponta para o atual primeiro elemento apontado por aux2
        //free(aux2); ????
        printf("\nLimpou no"); //mensagem de debug
    }
    free(ptlista); //limpo o ptlista da memoria
    printf("\n\nLimpou ptlista"); //mensagem de debug
}

no *alocaNo(int x){
     no *novoNo = (no *)malloc(sizeof(no)); //crio um novo no 
     
     if(novoNo == NULL){ //testo o se o novoNo foi alocado corretamente
        printf("\nErro ao alocar memoria\n"); //mensagem de debug
        return NULL; //retorna null indicando erro de alocacao
    }

    novoNo->chave = x; //coloca meu x na chave do no
    novoNo->prox = NULL; //proximo elemento desse no deve ser nulo para caso ele seja o ultimo elemento da lista

    return novoNo; //retorno o endereco do novoNo
}

int main(){
    no *ptlista = malloc(sizeof(no)); //Cria o no cabeca    
    ptlista->prox = NULL; //lista vazia o primeiro lemento e NULL   

    no *testeDeRemocao = removeLista(ptlista, 2); //teste de remocao sem nada na lista
    if(testeDeRemocao == NULL){
        printf("\nErro na primeira remocao\n"); //mensagem de debug
    }

    free(testeDeRemocao); //limpa o espaco por seguranca
 
    no *no1 = alocaNo(5); //Aloca varios nos para inserir na lista
    no *no2 = alocaNo(10);
    no *no3 = alocaNo(15);
    no *no4 = alocaNo(20);
    no *no5 = alocaNo(30);

    printf("\nResultado de insercao de 5:%d",insereLista(ptlista, no1)); //insercoes e retorno das chamadas de insercao
    printf("\nResultado de insercao de 10:%d",insereLista(ptlista, no2));
    printf("\nResultado de insercao de 15:%d",insereLista(ptlista, no3));
    printf("\nResultado de insercao de 20:%d",insereLista(ptlista, no4));
    printf("\nResultado de insercao de 30:%d\n",insereLista(ptlista, no5));

    imprimeLista(ptlista); //imprime a lista para ver se inseriu corretamente

    printf("\n--------------------\n");

    no *testeRemove = removeLista(ptlista, 5); //remover um item presente na lista
    no *testeRemove2 = removeLista(ptlista, 22); //remover um item que nao esta na lista
    if(testeRemove2 == NULL){ //se a remocao do item que nao esta na lista falhar retorna null
        printf("Remove NULL\n");
    }

    free(testeRemove); //limpa o no de teste de remocao
    free(testeRemove2); //limpa o no de teste de remocao

    imprimeLista(ptlista); //imprime a lista para ver se foi apagado o elemento correto

    no *no6 = alocaNo(25); //novo elemento criado
    printf("\n\nResultado de insere lista:%d\n",insereLista(ptlista, no6)); //insere +1 elemento
    
    imprimeLista(ptlista); //imprime a list atualizada

    no *no7 = alocaNo(15); //novo elemento criado
    printf("\n\nResultado de insere lista:%d\n",insereLista(ptlista, no7)); //tenta inserir na lista um elemento ja existente na lista

    liberaLista(ptlista); //funcao para remover a lista da memoria

    return 0;
}




/*
no *aux1 = ptlista->prox;

        while (aux1 != NULL) { //enquanto nao chegar ao final continua a busca
            
            if(aux1 < x){ //se ptlista for = ao valor procurado
                *ant = aux1; //passa o ant pra frente
                aux1 = ptlista->prox; //passa o ptlista pra frente

            }else if(ptlista == x){ //achado o valor 
                *pont = ptlista; //grava o valor em pont
                ptlista = NULL;
            } 
        } 
        pont = NULL; //nao achou o valor na lista 

        */
