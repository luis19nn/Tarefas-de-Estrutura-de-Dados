#include <stdio.h>
#include <stdlib.h>
#include "ListaDENoDescritor.h"

/*
### STRUCT DA LISTA ###
*/

struct ED_LE {
    int dado;
    struct ED_LE *prox;
};

struct descritor {
    struct ED_LE *inicio;
    struct ED_LE *final;
    int qtd;
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

    if (li != NULL) {
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    
    return li;
}

void liberaLista(Lista* li) {
    if (li != NULL) {
        Nodo* no;
        while (li->inicio != NULL) {
            no = li->inicio;
            li->inicio = li->inicio->prox;
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
    
    return li->qtd;
}

int listaCheia() {
    return 0;
}

int listaVazia(Lista* li) {
    if (li == NULL)
        return 1;
    if (li->inicio == NULL)
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
    no->prox = li->inicio;

    if (li->inicio == NULL)
        li->final = no;

    li->inicio = no;
    li->qtd++;

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
        no->prox = li->inicio;
        li->inicio = no;

        li->qtd++;

        return 1;
    } else {
        Nodo *ant, *atual = li->inicio;
        while (atual != NULL && atual->dado < dadoNovo) {
            ant = atual;
            atual = atual->prox;
        }

        if (atual == li->inicio) {
            no->prox = li->inicio;
            li->inicio = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }

        li->qtd++;

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

    if (li->inicio == NULL)
        li->inicio = no;
    else
        li->final->prox = no;
    
    li->final = no;
    li->qtd++;

    return 1;
}



/*
### REMOÇÃO DA LISTA ###
*/

int removeListaInicio(Lista* li) {
    if (li == NULL)
        return 0;
    if (li->inicio == NULL)
        return 0;

    Nodo *no = li->inicio;
    li->inicio = no->prox;
    free(no);

    if (li->inicio == NULL)
        li->final = NULL;
    
    li->qtd--;

    return 1;
}

int removeListaQualquer(Lista* li, int dadoASerRemovido) {
    if (li == NULL)
        return 0;

    Nodo *ant, *no = li->inicio;
    while (no != NULL && no->dado != dadoASerRemovido) {
        ant = no;
        no = no->prox;
    }

    if (no == NULL)
        return 0;
    
    if (no == li->inicio) {
        li->inicio = NULL;
        li->final = NULL;
    } else {
        ant->prox = no->prox;
        li->final = NULL;
    }

    free(no);

    li->qtd--;

    return 1;
}

int removeListaFinal(Lista* li) {
    if (li == NULL)
        return 0;
    if (li->inicio == NULL)
        return 0;

    Nodo *ant, *no = li->inicio;
    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }

    if (no == li->inicio) {
        li->inicio = NULL;
        li->final = NULL;
    } else {
        ant->prox = no->prox;
        li->final = ant;
    }

    free(no);

    li->qtd--;

    return 1;
}



/*
### CONSULTA NA LISTA ###
*/

int consultaListaPosicao(Lista* li, int posicaoInformada, int *dadoConsultado) {
    if (li == NULL || posicaoInformada <= 0)
        return 0;

    Nodo *no = li->inicio;
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

    Nodo *no = li->inicio;
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
    if (li->inicio == NULL)
        return 0;
    
    Nodo *no = li->inicio;
    printf("\nEstes sao os valores alocados na lista: ");
    while (no != NULL) {
        printf("%d ", no->dado);
        no = no->prox;
    }
    printf("\n");

    return 1;
}
