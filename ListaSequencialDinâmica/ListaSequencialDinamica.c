#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencialDinamica.h"

/*
### STRUCT DA LISTA ###
*/

struct ED_LE {
    int *dados;
    int qtd, elemt;
};

/*
### FUNÇÕES AUXILIARES ###
*/

void insereLista_AuxiliarInterface(ListaD* li, int inicioMeioFim) {
    if (listaCheia(li)) {
        printf("\nERRO AO INSERIR! A lista esta cheia!\n");
    } else {
        int numeroAInserir;
        printf("\nDigite o valor a ser inserido na lista: ");
        scanf("%d", &numeroAInserir);

        if (inicioMeioFim == 0) {
            int liInsereInicio = insereListaInicio(li, numeroAInserir);

            if (liInsereInicio) {
                printf("\nNumero inserido com sucesso no inicio da lista!\n");
            } else {
                printf("\nERRO AO INSERIR! A lista esta nula!\n");
            }
        }

        if (inicioMeioFim == 1) {
            int liInsereFinal = insereListaFinal(li, numeroAInserir);

            if (liInsereFinal) {
                printf("\nNumero inserido com sucesso no final da lista!\n");
            } else {
                printf("\nERRO AO INSERIR! A lista esta nula!\n");
            }
        }

        if (inicioMeioFim == 2) {
            int liInsereOrdenada = insereListaOrdenada(li, numeroAInserir);

            if (liInsereOrdenada) {
                printf("\nNumero inserido com sucesso no meio da lista, de forma ordenada!\n");
            } else {
                printf("\nERRO AO INSERIR! A lista esta nula!\n");
            }
        }
    }
}

void removeLista_AuxiliarInterface(ListaD* li, int inicioMeioFim) {
    if (li->qtd == 0) {
        printf("\nERRO AO REMOVER! A lista esta vazia!\n");
    } else {
        if (inicioMeioFim == 0) {
            int liRemoveInicio = removeListaInicio(li);

            if (liRemoveInicio) {
                printf("\nNumero removido com sucesso do inicio da lista!\n");
            } else {
                printf("\nERRO AO REMOVER! A lista esta nula!\n");
            }
        }

        if (inicioMeioFim == 1) {
            int liRemoveFinal = removeListaFinal(li);

            if (liRemoveFinal) {
                printf("\nNumero removido com sucesso do final da lista!\n");
            } else {
                printf("\nERRO AO REMOVER! A lista esta nula!\n");
            }
        }

        if (inicioMeioFim == 2) {
            int numeroARemover;
            printf("\nDigite o valor a ser removido da lista: ");
            scanf("%d", &numeroARemover);

            int liRemoveQualquer = removeListaQualquer(li, numeroARemover);

            if (liRemoveQualquer) {
                printf("\nNumero removido com sucesso da lista!\n");
            } else {
                printf("\nERRO AO REMOVER! A lista esta nula ou o numero nao foi encontrado!\n");
            }
        }
    }
}



/*
### CRIAÇÃO E LIBERAÇÃO DA LISTA ###
*/

ListaD* criaLista() {
    ListaD* li;
    li = (ListaD*) malloc(sizeof(struct ED_LE));

    if (li != NULL)
        li->qtd = 0;

    return li;
}

void liberaLista(ListaD* li) {
    free(li);
}



/*
### INFORMAÇÕES DA LISTA ###
*/

int tamanhoLista(ListaD* li) {
    if (li == NULL)
        return -1;
    else
        return li->qtd;
}

int listaCheia(ListaD* li) {
    if (li == NULL)
        return -1;

    return (li->qtd >= li->elemt);
}

int listaVazia(ListaD* li) {
    if (li == NULL)
        return -1;

    return (li->qtd == 0);
}



/*
### INSERÇÃO NA LISTA ###
*/

int insereListaInicio(ListaD* li, int numeroNovo) {
    if (li == NULL)
        return 0;
    if (listaCheia(li))
        return 0;

    int i;
    for (i = li->qtd-1; i >= 0; i--)
        li->dados[i+1] = li->dados[i];

    li->dados[0] = numeroNovo;
    li->qtd++;

    return 1;
}

int insereListaOrdenada(ListaD* li, int numeroNovo) {
    if (li == NULL)
        return 0;
    if (listaCheia(li))
        return 0;

    int k, i = 0;
    while (i < li->qtd && li->dados[i] < numeroNovo)
        i++;

    for (k = li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = numeroNovo;
    li->qtd++;

    return 1;
}

int insereListaFinal(ListaD* li, int numeroNovo) {
    if (li == NULL)
        return 0;
    if (listaCheia(li))
        return 0;

    li->dados[li->qtd] = numeroNovo;
    li->qtd++;

    return 1;
}



/*
### REMOÇÃO DA LISTA ###
*/

int removeListaInicio(ListaD* li) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    if (li->qtd > li->elemt)
        return 0;

    int k = 0;
    for (k = 0; k < li->qtd; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;

    return 1;
}

int removeListaQualquer(ListaD* li, int numeroASerRemovido) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    if (li->qtd > li->elemt)
        return 0;

    int k, i = 0;
    while(i < li->qtd && li->dados[i] != numeroASerRemovido)
        i++;

    if (i == li->qtd)
        return 0;

    for (k = i; k < li->qtd; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;

    return 1;
}

int removeListaFinal(ListaD* li) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    if (li->qtd > li->elemt)
        return 0;

    li->qtd--;

    return 1;
}



/*
### CONSULTA NA LISTA ###
*/

int consultaListaPosicao(ListaD* li, int posicaoInformada, int *numeroConsultado) {
    if (li == NULL || posicaoInformada <= 0 || posicaoInformada > li->qtd)
        return 0;

    *numeroConsultado = li->dados[posicaoInformada-1];

    return 1;
}

int consultaListaElemento(ListaD* li, int numeroInformado, int *posicaoConsultada) {
    int i, achou = 0;
    for(i = 0; i < li->qtd; i++) {
        if(li->dados[i] == numeroInformado) {
            *posicaoConsultada = i+1;
            achou = 1;
            break;
        }
    }

    if(achou)
        return 1;

    return 0;
}

int imprimeLista(ListaD* li) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    if (li->qtd > li->elemt)
        return 0;

    int i;
    printf("\nEstes sao os valores alocados na lista: ");
    for (i = 0; i < li->qtd; i++)
        printf("%d ", li->dados[i]);
    printf("\n");

    return 1;
}
