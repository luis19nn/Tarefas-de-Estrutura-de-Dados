#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void bubbleSort(int *V, int N) {
    int i, continua, aux, fim = N;
    do {
        continua = 0;
        for (i = 0; i < fim - 1; i++) {
            if (V[i] > V[i + 1]) {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}

int main() {
    int vetorOrdenado[MAX], vetorContrario[MAX], i, j;
    
    for (i = 0, j = MAX-1; i < MAX, j >= 0; i++, j--) {
        vetorOrdenado[i] = i + 1;
        vetorContrario[i] = j + 1;
    }
    
    printf("\nANTES DO BUBBLE SORT\n");

    printf("\nvetorOrdenado[1] = %d\n", vetorOrdenado[0]);
    printf("vetorContrario[1] = %d\n", vetorContrario[0]);

    printf("\nvetorOrdenado[1000] = %d\n", vetorOrdenado[999]);
    printf("vetorContrario[1000] = %d\n", vetorContrario[999]);

    bubbleSort(vetorOrdenado, MAX);
    bubbleSort(vetorContrario, MAX);

    printf("\n\nDEPOIS DO BUBBLE SORT\n");

    printf("\nvetorOrdenado[1] = %d\n", vetorOrdenado[0]);
    printf("vetorContrario[1] = %d\n", vetorContrario[0]);

    printf("\nvetorOrdenado[1000] = %d\n", vetorOrdenado[999]);
    printf("vetorContrario[1000] = %d\n", vetorContrario[999]);

    return 0;
}