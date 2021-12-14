#ifndef LISTASEQUENCIALESTATICA_H_INCLUDED
#define LISTASEQUENCIALESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
### DEFINIÇÃO DO TAMANHO MÁXIMO DA LISTA ###
*/

#define MAX 5



/*
### TYPEDEF DA LISTA ###
*/

typedef struct ED_LE ListaE;


/*
### FUNÇÕES AUXILIARES ###
*/

void insereLista_AuxiliarInterface(ListaE* li, int inicioMeioFim);

void removeLista_AuxiliarInterface(ListaE* li, int inicioMeioFim);



/*
### CRIAÇÃO E LIBERAÇÃO DA LISTA ###
*/

ListaE* criaLista();

void liberaLista(ListaE* li);



/*
### INFORMAÇÕES DA LISTA ###
*/

int tamanhoLista(ListaE* li);

int listaCheia(ListaE* li);

int listaVazia(ListaE* li);



/*
### INSERÇÃO NA LISTA ###
*/

int insereListaInicio(ListaE* li, int numeroNovo);

int insereListaOrdenada(ListaE* li, int numeroNovo);

int insereListaFinal(ListaE* li, int numeroNovo);



/*
### REMOÇÃO DA LISTA ###
*/

int removeListaInicio(ListaE* li);

int removeListaQualquer(ListaE* li, int numeroASerRemovido);

int removeListaFinal(ListaE* li);



/*
### CONSULTA NA LISTA ###
*/

int consultaListaPosicao(ListaE* li, int posicaoInformada, int *numeroConsultado);

int consultaListaElemento(ListaE* li, int numeroInformado, int *posicaoConsultada);

int imprimeLista(ListaE* li);



#endif // LISTASEQUENCIALESTATICA_H_INCLUDED
