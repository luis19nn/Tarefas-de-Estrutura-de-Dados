#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularJosephus.h"
#include "ListaCircularJosephus.c"

int main() {
    Lista *li;
    int pular;
    char primeiroSoldado;

    li = criaLista(li);

    nomeSoldados(li);

    printf("\nA contagem inicia no soldado: ");
    scanf("%c", &primeiroSoldado);

    inicioContagem(li, primeiroSoldado);

    printf("\nDigite o numero N: ");
    scanf("%d", &pular);

    contagem(li, pular);

    liberaLista(li);
    return 0;
}
