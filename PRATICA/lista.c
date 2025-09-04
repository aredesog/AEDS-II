#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "lista.h" 

struct node {
    int data;
    struct node *next;
}*p,*tmp,*tmp1;

void inserir_fim(int elemento) {
    tmp = p;
    tmp1 = (struct node*) malloc (sizeof(struct node));
    tmp1->data=elemento;
    tmp1->next=NULL;
    if (p == NULL) {
        p = tmp1;
    } else {
        while (tmp->next!=NULL) {
            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }
 }

void inserir_inicio(int elemento) {
     tmp = p;
     tmp1 = (struct node*) malloc (sizeof(struct node));
     tmp1->data=elemento;
     tmp1->next = p;
     p=tmp1;
}

void apagar(int ele) {
    tmp = p;
    struct node *pre=tmp;
    while (tmp != NULL) {
        if (tmp->data==ele) {
            if (tmp == p) {
                p = tmp->next;
                free(tmp);
                return;
            } else {
                pre->next=tmp->next;
                free(tmp);
                return;
            }
        } else {
            pre = tmp;
            tmp = tmp->next;
        }
    }
    printf("\n Valor não encontrado! ");
 }
 
void apagar_inicio() {  
    tmp = p;
    if (p == NULL) {
        printf("\n Nenhum elemento deletado ");
    } else {
        printf("\nElemento deletado - %d", p->data);
        p = p->next;
    }
 }
 
void apagar_fim() { 
    tmp=p;
    struct node* pre;
    if(p == NULL) {
        printf("\n Nenhum elemento deletado ");
    } else if (p->next == NULL) {
        printf("\nElemento deletado - %d", p->data);
        p = NULL;
    } else {
        while (tmp->next != NULL) {
            pre=tmp;
            tmp=tmp->next;
        }
        pre->next=NULL;
        printf("\nElemento deletado - %d", tmp->data);
    }
}

bool ehVazia() {
    if (p == NULL) {
        return (1);
    } else {
        return (0);
    }
}
void imprimir() {
    tmp = p;
    while (tmp != NULL) {
        printf("\n %d",tmp->data);
        tmp = tmp->next;
    }
}

int obter_primeiro(void) {
    tmp = p;
    if (p == NULL) {
        printf("\n Nenhum elemento encontrado ");
    } else {
        return (p->data);
    }
}

int obter_ultimo(void) {
    tmp = p;
    struct node* pre;
    if (p == NULL) {
        printf("\n Nenhum elemento encontrado ");
        return (0);
    } else if (p->next==NULL) {
        return(p->data);
    } else {
        while (tmp->next!=NULL) {
            pre=tmp;
            tmp=tmp->next;
        }
        pre->next=NULL;
        return(tmp->data);
    }
}

void inserirPosicao(int elemento, int posicao){
    // Verificar se a posição é válida
    if (posicao < 0) {
        printf("\n Posição inválida! Deve ser >= 0"); //Posição Negativa, não tem como!
        return;
    }
    
    // Criar o novo nó
    tmp1 = (struct node*) malloc (sizeof(struct node));
    tmp1->data = elemento;
    
    // Caso especial: inserir na posição 0 (início)
    if (posicao == 0) {
        tmp1->next = p;
        p = tmp1;
        return;
    }
    
    // Percorrer até a posição anterior ao local de inserção
    tmp = p; // O tmp é a variavel que vai localizar a posição que sera inserida o nosso novo numero.
    int contador = 0;
    
    // Verificar se a lista tem elementos suficientes
    while (tmp != NULL && contador < posicao - 1) { //tmp = NULL, nao foi selecionado nenhum valor p/ inserção, e contador < posição -1, e para evitar que ultrapasse o tamanho dalista.
        tmp = tmp->next;
        contador++;
    } //tmp varre a lista, tmp1 ele define o local
    
    // Se chegamos ao final antes da posição desejada
    if (tmp == NULL) {
        printf("\n Posição inválida! Lista muito pequena");
        free(tmp1);
        return;
    }
    
    // Inserir o novo nó na posição correta
    tmp1->next = tmp->next; //tm1 aponta pra posição escolhida
    tmp->next = tmp1; //tmp aponta para o proximo
}

void removerPosicao(int posicao){
    // Verificar se a posição é válida
    if (posicao < 0) {
        printf("\n Posição inválida! Deve ser >= 0");
        return;
    }
    
    // Verificar se a lista está vazia
    if (p == NULL) {
        printf("\n Lista vazia! Nenhum elemento removido");
        return;
    }
    
    // Caso especial: remover da posição 0 (primeiro elemento)
    if (posicao == 0) {
        tmp = p;
        printf("\n Elemento removido: %d", p->data);
        p = p->next;//para nao remover o p, ele manda o p para proximo
        free(tmp); //e  aqui remover o antigo que que é o tmp
        return;
    }
    
    // Percorrer até a posição anterior ao elemento a ser removido
    tmp = p;
    struct node* anterior = NULL; //o apontamento do anterior sera igual ao aopontamento de nulo, pois ja achamos em tmp o valor a ser removido
    int contador = 0;
    
    while (tmp != NULL && contador < posicao) {
        anterior = tmp;  // passa para a proxima posição atras do tmp
        tmp = tmp->next; //passa para proxima posição na frente (pensa como duas caixinhas)
        contador++;
    }
    
    // Verificar se a posição existe
    if (tmp == NULL) {
        printf("\n Posição inválida! Lista muito pequena");
        return;
    }
    
    // Remover o nó da posição especificada
    printf("\n Elemento removido: %d", tmp->data);
    anterior->next = tmp->next;
    free(tmp);
}

int obterPosicao(int posicao){
    // Verificar se a posição é válida
    if (posicao < 0) {
        printf("\n Posição inválida! Deve ser >= 0");
        return -1;
    }
    
    // Verificar se a lista está vazia
    if (p == NULL) { // p é o primeiro e terá seu valor após alguem inserir alguma coisa.
        printf("\n Lista vazia!");
        return -1;
    }
    
    // Percorrer a lista até a posição desejada
    tmp = p;
    int contador = 0;
    
    while (tmp != NULL && contador < posicao) {
        tmp = tmp->next;
        contador++;
    }
    
    // Verificar se a posição existe
    if (tmp == NULL) {
        printf("\n Posição inválida! Lista muito pequena");
        return -1;
    }
    
    // Retornar o valor encontrado
    return tmp->data;
}


void main() { 
  int val, n;
  p = NULL;
  do {
    printf("\n************************* MENU ************************");
    printf("\n1.Inserir no fim");
     printf("\n2.Inserir no início");
     printf("\n3.Apagar um elemento em particular");
     printf("\n4.Apagar do início");
     printf("\n5.Apagar do fim");
     printf("\n6.Imprimir lista");
     printf("\n7.É vazia?");
     printf("\n8.Obter primeiro");
     printf("\n9.Obter último");
     printf("\n10.Inserir em posição específica");
     printf("\n11.Remover de posição específica");
     printf("\n12.Obter elemento de posição específica");
     printf("\n0.Sair");
     printf("\nEntre sua opção : ");
     scanf("%d",&n);
     switch(n) {
        case 1: printf("\nDigite o valor ");
                scanf("%d",&val);
                inserir_fim(val);
                break;
         case 2: printf("\nDigite o valor ");
                scanf("%d",&val);
                inserir_inicio(val);
                break;
         case 3: printf("\nDigite o valor ");
                scanf("%d",&val);
                apagar(val);
                break;
         case 4: 
                apagar_inicio();
                break;
         case 5: 
                apagar_fim();
                break;
         case 6: imprimir();
                break;
         case 7: if (ehVazia() == 1) {
                    printf("\nLista vazia");
                } else {
                    printf("\nLista não vazia");
                }
                break;
        case 8: val = obter_primeiro();
                if (val != 0) {
                    printf("%d", val);
                }
                break;
        case 9: val = obter_ultimo();
                if (val != 0) {
                    printf("%d", val);
                }
                break;
        case 10: printf("\nDigite o valor ");
                scanf("%d",&val);
                printf("\nDigite a posição ");
                int pos;
                scanf("%d",&pos);
                inserirPosicao(val, pos);
                break;
        case 11: printf("\nDigite a posição ");
                int pos_rem;
                scanf("%d",&pos_rem);
                removerPosicao(pos_rem);
                break;
        case 12: printf("\nDigite a posição ");
                int pos_obt;
                scanf("%d",&pos_obt);
                val = obterPosicao(pos_obt);
                if (val != -1) {
                    printf("\nElemento na posição %d: %d", pos_obt, val);
                }
                break;
        case 0: exit(0);
                break;
        default: printf("\n Opção errada!");
                break;
        }
    } while(1);

 }