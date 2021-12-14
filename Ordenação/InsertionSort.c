#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void insertionSort(int *V, int N) {
    int i, j, aux;

    for (i = 1; i < N; i++) {
        aux = V[i];

        for (j = i; (j > 0) && (aux < V[j - 1]); j--) {
            V[j] = V[j - 1];
        }

        V[j] = aux;
    }
}

int main() {
    int vetorOrdenado[MAX], vetorContrario[MAX], i, j;
    
    for (i = 0, j = MAX-1; i < MAX, j >= 0; i++, j--) {
        vetorOrdenado[i] = i + 1;
        vetorContrario[i] = j + 1;
    }
    
    printf("\nANTES DO INSERTION SORT\n");

    printf("\nvetorOrdenado[1] = %d\n", vetorOrdenado[0]);
    printf("vetorContrario[1] = %d\n", vetorContrario[0]);

    printf("\nvetorOrdenado[1000] = %d\n", vetorOrdenado[999]);
    printf("vetorContrario[1000] = %d\n", vetorContrario[999]);

    insertionSort(vetorOrdenado, MAX);
    insertionSort(vetorContrario, MAX);

    printf("\n\nDEPOIS DO INSERTION SORT\n");

    printf("\nvetorOrdenado[1] = %d\n", vetorOrdenado[0]);
    printf("vetorContrario[1] = %d\n", vetorContrario[0]);

    printf("\nvetorOrdenado[1000] = %d\n", vetorOrdenado[999]);
    printf("vetorContrario[1000] = %d\n", vetorContrario[999]);

    return 0;
}