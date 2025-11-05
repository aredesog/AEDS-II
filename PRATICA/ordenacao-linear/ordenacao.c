#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

// Counting Sort (para inteiros nao-negativos)
void counting_sort(int arr[], int n, int max_value) {
	if (n <= 0) return;
	int range = max_value + 1;
	int *count = (int*)calloc(range, sizeof(int));
	int *output = (int*)malloc(n * sizeof(int));
	if (!count || !output) {
		fprintf(stderr, "Falha de alocacao em counting_sort\n");
		free(count); free(output);
		return;
	}

	for (int i = 0; i < n; ++i) count[arr[i]]++;
	for (int i = 1; i < range; ++i) count[i] += count[i-1];
	// Construir saída estável
	for (int i = n-1; i >= 0; --i) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	// Copiar de volta
	for (int i = 0; i < n; ++i) arr[i] = output[i];

	free(count);
	free(output);
}

// Radix Sort (LSD) para inteiros nao-negativos
void radix_sort(int arr[], int n) {
	if (n <= 0) return;
	int i, max = arr[0];
	for (i = 1; i < n; ++i) if (arr[i] > max) max = arr[i];

	int *output = (int*)malloc(n * sizeof(int));
	int exp;
	for (exp = 1; max/exp > 0; exp *= 10) {
		int bucket[10] = {0};
		for (i = 0; i < n; ++i) bucket[(arr[i]/exp) % 10]++;
		for (i = 1; i < 10; ++i) bucket[i] += bucket[i-1];
		for (i = n-1; i >= 0; --i) {
			int idx = (arr[i]/exp) % 10;
			output[bucket[idx]-1] = arr[i];
			bucket[idx]--;
		}
		for (i = 0; i < n; ++i) arr[i] = output[i];
	}
	free(output);
}

// Bucket Sort para inteiros (usa n buckets e insercao simples em cada bucket)
void bucket_sort(int arr[], int n) {
	if (n <= 0) return;
	int i;
	int min = arr[0], max = arr[0];
	for (i = 1; i < n; ++i) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	if (min == max) return; // todos iguais

	// Estrutura de bucket simples com arrays dinamicos (realloc quando necessario)
	int bucket_count = n;
	int **buckets = (int**)malloc(bucket_count * sizeof(int*));
	int *sizes = (int*)calloc(bucket_count, sizeof(int));
	int *caps = (int*)malloc(bucket_count * sizeof(int));
	if (!buckets || !sizes || !caps) {
		fprintf(stderr, "Falha de alocacao em bucket_sort\n");
		free(buckets); free(sizes); free(caps);
		return;
	}
	for (i = 0; i < bucket_count; ++i) { buckets[i] = NULL; caps[i] = 0; }

	double range = (double)(max - min + 1);
	for (i = 0; i < n; ++i) {
		int idx = (int)(( (arr[i] - min) * (double)bucket_count ) / range);
		if (idx < 0) idx = 0; else if (idx >= bucket_count) idx = bucket_count-1;
		if (sizes[idx] + 1 > caps[idx]) {
			int newcap = (caps[idx] == 0) ? 4 : caps[idx]*2;
			int *tmp = (int*)realloc(buckets[idx], newcap * sizeof(int));
			if (!tmp) { fprintf(stderr, "realloc falhou\n"); continue; }
			buckets[idx] = tmp; caps[idx] = newcap;
		}
		buckets[idx][sizes[idx]++] = arr[i];
	}

	// Ordena cada bucket (insertion sort) e concatena
	int pos = 0;
	for (i = 0; i < bucket_count; ++i) {
		// insertion sort
		for (int j = 1; j < sizes[i]; ++j) {
			int key = buckets[i][j];
			int k = j-1;
			while (k >= 0 && buckets[i][k] > key) {
				buckets[i][k+1] = buckets[i][k];
				k--;
			}
			buckets[i][k+1] = key;
		}
		for (int j = 0; j < sizes[i]; ++j) arr[pos++] = buckets[i][j];
		free(buckets[i]);
	}

	free(buckets);
	free(sizes);
	free(caps);
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int a1[] = {4, 2, 2, 8, 3, 3, 1};
	int n1 = sizeof(a1)/sizeof(a1[0]);
	printf("Array original (counting): "); print_array(a1, n1);
	counting_sort(a1, n1, 8);
	printf("Counting Sort:        "); print_array(a1, n1);

	int a2[] = {29, 25, 3, 49, 9, 37, 21, 43};
	int n2 = sizeof(a2)/sizeof(a2[0]);
	printf("\nArray original (radix): "); print_array(a2, n2);
	radix_sort(a2, n2);
	printf("Radix Sort:           "); print_array(a2, n2);

	int a3[] = {42, 32, 33, 52, 37, 47, 51};
	int n3 = sizeof(a3)/sizeof(a3[0]);
	printf("\nArray original (bucket): "); print_array(a3, n3);
	bucket_sort(a3, n3);
	printf("Bucket Sort:          "); print_array(a3, n3);

	return 0;
}
