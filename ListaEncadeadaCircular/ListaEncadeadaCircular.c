#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeadaCircular.h"

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
### INFORMAÇÕES DA LISTA ###
*/

int tamanhoLista(Lista* li) {
    if (li == NULL || (*li) == NULL)
        return 0;
    
    int cont = 0;
    Nodo* no = *li;
    do {
        cont++;
        no = no->prox;
    } while (no != (*li));

    return cont;
}

int listaCheia() {
    return 0;
}

int listaVazia(Lista* li) {
    if (li == NULL && (*li) == NULL)
        return 1;
    else
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

    if ((*li) == NULL) {
        *li = no;
        no->prox = no;
    } else {
        Nodo *aux = *li;
        while (aux->prox != (*li))
            aux = aux->prox;
        
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }

    return 1;
}   

int insereListaOrdenada(Lista* li, int dadoNovo) {
    if (li == NULL)
        return 0;

    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if (no == NULL)
        return 0;
    
    no->dado = dadoNovo;

    if ((*li) == NULL) {
        *li = no;
        no->prox = no;
        
        return 1;
    } else {
        if ((*li)->dado > dadoNovo) {
            Nodo *atual = *li;
            while (atual->prox != (*li))
                atual = atual->prox;
            
            no->prox = *li;
            atual->prox = no;
            *li = no;

            return 1;
        }

        Nodo *ant = *li, *atual = (*li)->prox;
        while(atual != (*li) && atual->dado < dadoNovo) {
            ant = atual;
            atual = atual->prox;
        }

        ant->prox = no;
        no->prox = atual;

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
### REMOÇÃO DA LISTA ###
*/

int removeListaInicio(Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    
    if ((*li) == (*li)->prox) {
        free(*li);
        *li = NULL;

        return 1;
    }

    Nodo *atual = *li;
    while (atual->prox != (*li))
        atual = atual->prox;

    Nodo *no = *li;
    atual->prox = no->prox;
    *li = no->prox;
    
    free(no);

    return 1;
}

int removeListaQualquer(Lista* li, int dadoASerRemovido) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    
    Nodo *no = *li;
    if (no->dado == dadoASerRemovido) {
        return removeListaInicio(li);
    }

    Nodo *ant = no;
    no = no->prox;
    while (no != (*li) && no->dado != dadoASerRemovido) {
        ant = no;
        no = no->prox;
    }

    if (no == (*li))
        return 0;
    
    ant->prox = no->prox;

    free(no);

    return 1;
}

int removeListaFinal(Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    
    if ((*li) == (*li)->prox) {
        free(*li);
        *li = NULL;

        return 1;
    }

    Nodo *ant, *no = *li;
    while (no->prox != (*li)) {
        ant = no;
        no = no->prox;
    }

    ant->prox = no->prox;
    
    free(no);

    return 1;
}



/*
### CONSULTA NA LISTA ###
*/

int consultaListaPosicao(Lista* li, int posicaoInformada, int *dadoConsultado) {
    if (li == NULL || (*li) == NULL || posicaoInformada <= 0)
        return 0;

    Nodo *no = *li;
    int i = 1;
    while (no->prox != (*li) && i < posicaoInformada) {
        no = no->prox;
        i++;
    }

    if (i != posicaoInformada) {
        return 0;
    } else {
        *dadoConsultado = no->dado;

        return 1;
    }
}

int consultaListaElemento(Lista* li, int dadoInformado, int *posicaoConsultada) {
    if (li == NULL || (*li) == NULL)
        return 0;

    Nodo *no = *li;
    int i = 1;
    while (no->prox != (*li) && no->dado != dadoInformado) {
        no = no->prox;
        i++;
    }

    if (no->dado != dadoInformado) {
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
    do {
        printf("%d ", no->dado);
        no = no->prox;
    } while (no != (*li));
    printf("\n");

    return 1;
}
