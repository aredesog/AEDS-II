#ifndef ORDENACAO_H
#define ORDENACAO_H

// Protótipos das funções de ordenação
// counting_sort: arr deve conter inteiros nao-negativos; max_value é o maior valor em arr
void counting_sort(int arr[], int n, int max_value);

// radix_sort: ordena inteiros nao-negativos usando LSD radix (base 10)
void radix_sort(int arr[], int n);

// bucket_sort: implementado para inteiros; usa n buckets e insertion sort em cada bucket
void bucket_sort(int arr[], int n);

// utilitários
void print_array(int arr[], int n);

#endif // ORDENACAO_H
