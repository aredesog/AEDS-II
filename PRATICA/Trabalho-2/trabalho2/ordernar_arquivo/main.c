#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ordenacao.h"


/*
 Trabalho 2 - AEDS II Prática 
Guilherme Aredes
Carlos Eduardo
Marcos Felipe
*/

// Dividir o arquivo grande em blocos menores
int dividirEmBlocos(const char* arquivoEntrada, int tam_bloco) {
    FILE* arquivo_in = fopen(arquivoEntrada, "r");
    if (arquivo_in == NULL) {
        printf("Erro ao abrir arquivo de entrada.\n");
        return 0;
    }

    int* bloco_buf = (int*)malloc(tam_bloco * sizeof(int));
    if (bloco_buf == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(arquivo_in);
        return 0;
    }

    int valor, cont = 0, idx_bloco = 0;

    while (fscanf(arquivo_in, "%d", &valor) == 1) {
        bloco_buf[cont++] = valor;

        // Quando atingir o tamanho do bloco, ordena e grava
        if (cont == tam_bloco) {
            idx_bloco++;
            ordenacao(bloco_buf, cont); // usa a função Bubble Sort

            char arquivo_bloco[50];
            sprintf(arquivo_bloco, "bloco_%d.txt", idx_bloco);

            FILE* fp_bloco = fopen(arquivo_bloco, "w");
            if (fp_bloco == NULL) {
                printf("Erro ao criar arquivo %s\n", arquivo_bloco);
                free(bloco_buf);
                fclose(arquivo_in);
                return 0;
            }

            for (int i = 0; i < cont; i++)
                fprintf(fp_bloco, "%d\n", bloco_buf[i]);

            fclose(fp_bloco);
            cont = 0; // reinicia o contador
        }
    }

    // Grava o último bloco se sobrar algo
    if (cont > 0) {
        idx_bloco++;
        ordenacao(bloco_buf, cont);

        char arquivo_bloco[50];
        sprintf(arquivo_bloco, "bloco_%d.txt", idx_bloco);

        FILE* fp_bloco = fopen(arquivo_bloco, "w");
        if (fp_bloco == NULL) {
            printf("Erro ao criar arquivo %s\n", arquivo_bloco);
            free(bloco_buf);
            fclose(arquivo_in);
            return 0;
        }

        for (int i = 0; i < cont; i++)
            fprintf(fp_bloco, "%d\n", bloco_buf[i]);

        fclose(fp_bloco);
    }

    free(bloco_buf);
    fclose(arquivo_in);

    printf("Total de blocos criados: %d\n", idx_bloco);
    return idx_bloco;
}

//  Intercalar blocos ordenados (merge externo)
void intercalarBlocos(int qtdBlocos, const char* arquivoSaida) {
    FILE** arr_blocos = (FILE**)malloc(qtdBlocos * sizeof(FILE*));
    int* arr_valores = (int*)malloc(qtdBlocos * sizeof(int));
    int* arr_ativo = (int*)malloc(qtdBlocos * sizeof(int)); // 1 = ativo, 0 = inativo

    if (arr_blocos == NULL || arr_valores == NULL || arr_ativo == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    // Inicializa os blocos e lê o primeiro valor de cada um
    for (int i = 0; i < qtdBlocos; i++) {
        char bloco_nome[50];
        sprintf(bloco_nome, "bloco_%d.txt", i + 1);
        arr_blocos[i] = fopen(bloco_nome, "r");

        if (arr_blocos[i] != NULL && fscanf(arr_blocos[i], "%d", &arr_valores[i]) == 1) {
            arr_ativo[i] = 1;
        } else {
            arr_ativo[i] = 0;
        }
    }

    FILE* fp_saida = fopen(arquivoSaida, "w");
    if (fp_saida == NULL) {
        printf("Erro ao criar arquivo de saída.\n");
        for (int i = 0; i < qtdBlocos; i++) {
            if (arr_blocos[i] != NULL) fclose(arr_blocos[i]);
        }
        free(arr_blocos);
        free(arr_valores);
        free(arr_ativo);
        return;
    }

    while (1) {
        int menor_valor = INT_MAX;
        int idx_menor = -1;

        // Encontra o menor valor entre os blocos 
        for (int i = 0; i < qtdBlocos; i++) {
            if (arr_ativo[i] && arr_valores[i] < menor_valor) {
                menor_valor = arr_valores[i];
                idx_menor = i;
            }
        }

        if (idx_menor == -1) break; // nenhum bloco ativo -> fim

        // Escreve o menor valor no arquivo de saída
        fprintf(fp_saida, "%d\n", menor_valor);

        // Lê o próximo número do bloco de onde o menor saiu
        if (fscanf(arr_blocos[idx_menor], "%d", &arr_valores[idx_menor]) != 1) {
            arr_ativo[idx_menor] = 0; // fim do bloco
            fclose(arr_blocos[idx_menor]);
        }
    }

    fclose(fp_saida);
    printf("Arquivo final ordenado salvo em: %s\n", arquivoSaida);

    // Remove blocos temporários
    for (int i = 0; i < qtdBlocos; i++) {
        char bloco_nome[50];
        sprintf(bloco_nome, "bloco_%d.txt", i + 1);
        remove(bloco_nome);
    }

    // Libera memória
    free(arr_blocos);
    free(arr_valores);
    free(arr_ativo);
}

// Funçao principal
int main() {
    const char* arquivoEntrada = "output.txt";
    const char* arquivoSaida = "saida_ordenada.txt";
    int tamanhoBloco = 100000; // quantidade de números que cabem na RAM

    printf("=== Ordenacao Externa com Merge Sort ===\n");
    printf("Lendo arquivo: %s\n", arquivoEntrada);

    // Criar blocos menores
    int qtdBlocos = dividirEmBlocos(arquivoEntrada, tamanhoBloco);

    // Fazer o merge externo
    intercalarBlocos(qtdBlocos, arquivoSaida);

    printf("Processo concluído com sucesso!\n");
    return 0;
}
