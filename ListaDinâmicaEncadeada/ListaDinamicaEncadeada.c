#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaEncadeada.h"

/*
### STRUCT DA LISTA ###
*/

struct ED_LE {
    int dado;
    struct ED_LE *prox;
};

/*
### FUNÇÕES AUXILIARES ###
*/

void insereLista_AuxiliarInterface(Lista* li, int inicioMeioFim) {
    int dadoAInserir;
    printf("\nDigite o valor a ser inserido na lista: ");
    scanf("%d", &dadoAInserir);

    if (inicioMeioFim == 0) {
        int liInsereInicio = insereListaInicio(li, dadoAInserir);

        if (liInsereInicio) {
            printf("\nNumero inserido com sucesso no inicio da lista!\n");
        } else {
            printf("\nERRO AO INSERIR! A lista esta nula!\n");
        }
    }

    if (inicioMeioFim == 1) {
        int liInsereFinal = insereListaFinal(li, dadoAInserir);

        if (liInsereFinal) {
            printf("\nNumero inserido com sucesso no final da lista!\n");
        } else {
            printf("\nERRO AO INSERIR! A lista esta nula!\n");
        }
    }

    if (inicioMeioFim == 2) {
        int liInsereOrdenada = insereListaOrdenada(li, dadoAInserir);

        if (liInsereOrdenada) {
            printf("\nNumero inserido com sucesso no meio da lista, de forma ordenada!\n");
        } else {
            printf("\nERRO AO INSERIR! A lista esta nula!\n");
        }
    }
}

void removeLista_AuxiliarInterface(Lista* li, int inicioMeioFim) {
    if (listaVazia(li)) {
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
            int dadoARemover;
            printf("\nDigite o valor a ser removido da lista: ");
            scanf("%d", &dadoARemover);

            int liRemoveQualquer = removeListaQualquer(li, dadoARemover);

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

Lista* criaLista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL)
        *li = NULL;
    
    return li;
}

void liberaLista(Lista* li) {
    if (li != NULL) {
        Nodo* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}



/*
### INFORMAÇÕES DA LISTA ###
*/

int tamanhoLista(Lista* li) {
    if (li == NULL)
        return 0;
    
    int cont = 0;
    Nodo* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }

    return cont;
}

int listaCheia() {
    return 0;
}

int listaVazia(Lista* li) {
    if (li == NULL)
        return 1;
    if ((*li) == NULL)
        return 1;
    
    return 0;
}



/*
### INSERÇÃO NA LISTA ###
*/

int insereListaInicio(Lista* li, int dadoNovo) {
    if (li == NULL)
        return 0;

    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if (no == NULL)
        return 0;
    
    no->dado = dadoNovo;
    no->prox = (*li);
    *li = no;

    return 1;
}   

int insereListaOrdenada(Lista* li, int dadoNovo) {
    if (li == NULL)
        return 0;

    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if (no == NULL)
        return 0;
    
    no->dado = dadoNovo;

    if (listaVazia(li)) {
        no->prox = (*li);
        *li = no;

        return 1;
    } else {
        Nodo *ant, *atual = *li;
        while (atual != NULL && atual->dado < dadoNovo) {
            ant = atual;
            atual = atual->prox;
        }

        if (atual == *li) {
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }

        return 1;
    }
}

int insereListaFinal(Lista* li, int dadoNovo) {
    if (li == NULL)
        return 0;

    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if (no == NULL)
        return 0;
    
    no->dado = dadoNovo;
    no->prox = NULL;

    if ((*li) == NULL) {
        *li = no;
    } else {
        Nodo *aux = *li;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = no;
    }

    return 1;
}



/*
### REMOÇÃO DA LISTA ###
*/

int removeListaInicio(Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    Nodo *no = *li;
    *li = no->prox;
    free(no);

    return 1;
}

int removeListaQualquer(Lista* li, int dadoASerRemovido) {
    if (li == NULL)
        return 0;

    Nodo *ant, *no = *li;
    while (no != NULL && no->dado != dadoASerRemovido) {
        ant = no;
        no = no->prox;
    }

    if (no == NULL)
        return 0;
    
    if (no == *li) {
        *li = no->prox;
    } else {
        ant->prox = no->prox;
    }

    free(no);

    return 1;
}

int removeListaFinal(Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    Nodo *ant, *no = *li;
    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }

    if (no == (*li)) {
        *li = no->prox;
    } else {
        ant->prox = no->prox;
    }

    free(no);

    return 1;
}



/*
### CONSULTA NA LISTA ###
*/

int consultaListaPosicao(Lista* li, int posicaoInformada, int *dadoConsultado) {
    if (li == NULL || posicaoInformada <= 0)
        return 0;

    Nodo *no = *li;
    int i = 1;
    while (no != NULL && i < posicaoInformada) {
        no = no->prox;
        i++;
    }

    if (no == NULL) {
        return 0;
    } else {
        *dadoConsultado = no->dado;

        return 1;
    }
}

int consultaListaElemento(Lista* li, int dadoInformado, int *posicaoConsultada) {
    if (li == NULL)
        return 0;

    Nodo *no = *li;
    int i = 1;
    while (no != NULL && no->dado != dadoInformado) {
        no = no->prox;
        i++;
    }

    if (no == NULL) {
        return 0;
    } else {
        *posicaoConsultada = i;

        return 1;
    }
}

int imprimeLista(Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    
    Nodo *no = *li;
    printf("\nEstes sao os valores alocados na lista: ");
    while (no != NULL) {
        printf("%d ", no->dado);
        no = no->prox;
    }
    printf("\n");

    return 1;
}
