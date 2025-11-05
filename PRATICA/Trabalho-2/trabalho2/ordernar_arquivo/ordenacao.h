#ifndef ORDENCAO_H
#define ORDENCAO_H


// Ordenação por Bubble Sort
void ordenacao(int arr[], int n) {
    int tmp;
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - a - 1; b++) {
            if (arr[b] > arr[b + 1]) {
                tmp = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = tmp;
            }
        }
    }
}

#endif
