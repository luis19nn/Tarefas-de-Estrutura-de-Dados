#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularJosephus.h"

/*
### STRUCT DA LISTA ###
*/

struct ED_LE {
    char nome;
    struct ED_LE *prox;
};



/*
### CRIAÇÃO E LIBERAÇÃO DA LISTA ###
*/

Lista* criaLista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL)
        *li = NULL;
    
    return li;
}

void liberaLista(Lista* li) {
    if (li != NULL && (*li) != NULL) {
        Nodo* *aux, *no = *li;
        while ((*li) != no->prox) {
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}



/*
### INSERÇÃO NA LISTA ###
*/

int insereListaFinal(Lista* li, char nomeNovo) {
    if (li == NULL)
        return 0;

    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if (no == NULL)
        return 0;
    
    no->nome = nomeNovo;
    
    if ((*li) == NULL) {
        *li = no;
        no->prox = no;
    } else {
        Nodo *aux = *li;
        while (aux->prox != (*li))
            aux = aux->prox;
        
        aux->prox = no;
        no->prox = *li;
    }

    return 1;
}



/*
### IMPRESSÃO DA LISTA ###
*/

int imprimeLista(Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    
    Nodo *no = *li;
    printf("\nNomes dos soldados: ");
    do {
        printf("%c ", no->nome);
        no = no->prox;
    } while (no != (*li));
    printf("\n");

    return 1;
}



/*
### FUNÇÕES DE JOSEPHUS ###
*/

void nomeSoldados(Lista *li) {
    char nome;

    do {
        printf("\nDigite o nome dos soldados: ");
        scanf("%c", &nome);
        fflush(stdin);

        if (nome != ':')
            insereListaFinal(li, nome);
    } while (nome != ':');

    imprimeLista(li);
}

void inicioContagem(Lista *li, char primeiroSoldado) {
    Nodo *atual = *li;
    while (atual->prox != (*li) && atual->nome != primeiroSoldado)
        atual = atual->prox;

    if (atual->prox == (*li) && atual->nome != primeiroSoldado) {
        printf("\nSoldado nao encontrado!\n");
        exit(0);
    }

    *li = atual;
}

void contagem(Lista *li, int pular) {
    Nodo *atual, *ant;
    
    ant = atual = *li;
    
    int i;
    while (atual->prox != atual) {
        for (i = 1; i < pular; i++) {
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = atual->prox;

        printf("\n%c foi retirado.", atual->nome);

        free(atual);

        atual = ant->prox;
    }
    *li = atual;
 
    printf("\n\nSobrevivente: %c\n", atual->nome);
}