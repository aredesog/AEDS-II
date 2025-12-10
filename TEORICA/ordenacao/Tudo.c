#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void troca(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

// Função para imprimir o vetor
int imprime_vetor(int vetor[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n"); 
}
//-----------------------------------------------------------------------------------------------------------------------------------
//Implementação do bubbleSort 
void bubblesort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool trocou = false;
        for(int j = 0;j < n - i - 1; j++ ){
            if(arr[j] > arr[j + 1]){
                troca(&arr[j], &arr[j + 1]);
                trocou = true;
            } 
        }
        if(!trocou) break;    
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------
//implementação do MergeSort
void merge(int arr[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;  // Tamanho do subvetor esquerdo
    int n2 = dir - meio;        // Tamanho do subvetor direito
    
    // Criar arrays temporários
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    // Copiar dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[esq + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];
    
    // Mesclar os arrays temporários de volta em arr[esq..dir]
    int i = 0;    // Índice inicial do primeiro subvetor
    int j = 0;    // Índice inicial do segundo subvetor
    int k = esq; // Índice inicial do subvetor mesclado
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Liberar memória temporária
    free(L);
    free(R);
}

void mergeSort(int arr[], int esq, int dir, int n) {
    if (esq < dir) {
        // Encontra o ponto médio
        int meio = esq + (dir - esq) / 2;
        
        // Ordena a primeira e a segunda metade
        mergeSort(arr, esq, meio, n);
        mergeSort(arr, meio + 1, dir, n);
        
        // Mescla as duas metades ordenadas
        merge(arr, esq, meio, dir);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
//QuickSort
int particionar(int arr[], int esq, int dir) {
    int pivo = arr[dir];  // Escolhe o último elemento como pivô
    int i = esq - 1;     // Índice do menor elemento
    
    for (int j = esq; j < dir; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    
    // Coloca o pivô na posição correta
    troca(&arr[i + 1], &arr[dir]);
    return i + 1;
}

// Função principal do Quick Sort
void quickSort(int arr[], int esq, int dir) {
    if (esq < dir) {
        // pi é o índice de particionamento, arr[pi] está na posição correta
        int pi = particionar(arr, esq, dir);
        
        // Ordena recursivamente os elementos antes e depois da partição
        quickSort(arr, esq, pi - 1);
        quickSort(arr, pi + 1, dir);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
//Heapsort
void heapify(int arr[], int n, int i) {
    int maior = i;        // Inicializa o maior como raiz
    int esq = 2 * i + 1;  // Filho esquerdo
    int dir = 2 * i + 2;  // Filho direito
    
    // Se o filho esquerdo existe e é maior que a raiz
    if (esq < n && arr[esq] > arr[maior]) {
        maior = esq;
    }
    
    // Se o filho direito existe e é maior que o maior até agora
    if (dir < n && arr[dir] > arr[maior]) {
        maior = dir;
    }
    
    // Se o maior não é a raiz
    if (maior != i) {
        troca(&arr[i], &arr[maior]);
        
        // Recursivamente heapify a subárvore afetada
        heapify(arr, n, maior);
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int n) {
    // 1. Construir max-heap (reorganizar o array)
    // Começa do último nó não-folha e vai até a raiz
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // 2. Extrair elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual (maior elemento) para o final
        troca(&arr[0], &arr[i]);
        
        // Chama heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------
//Tabela Hash
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




int main(){

    int arr[5] = {22, 12, 1, 44, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Vetor original: ");
    imprime_vetor(arr, n);

    //printf("\n--- BubbleSort ---\n");
    //bubblesort(arr, n);

    printf("\n--- MergeSort ---\n");
    mergeSort(arr, 0, n - 1, n);
/*
    printf("\n--- QuickSort ---\n");
    quickSort(arr, n);

    printf("\n--- HeapSort ---\n");
    heapSort(arr, n);
*/

    printf("\nVetor ordenado: ");
    imprime_vetor(arr, n);
    
    return 0;
}