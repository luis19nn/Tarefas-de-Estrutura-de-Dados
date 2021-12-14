#ifndef LISTASEQUENCIALDINAMICA_H_INCLUDED
#define LISTASEQUENCIALDINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
### TYPEDEF DA LISTA ###
*/

typedef struct ED_LE ListaD;


/*
### FUNÇÕES AUXILIARES ###
*/

void insereLista_AuxiliarInterface(ListaD* li, int inicioMeioFim);

void removeLista_AuxiliarInterface(ListaD* li, int inicioMeioFim);



/*
### CRIAÇÃO E LIBERAÇÃO DA LISTA ###
*/

ListaD* criaLista();

void liberaLista(ListaD* li);



/*
### INFORMAÇÕES DA LISTA ###
*/

int tamanhoLista(ListaD* li);

int listaCheia(ListaD* li);

int listaVazia(ListaD* li);



/*
### INSERÇÃO NA LISTA ###
*/

int insereListaInicio(ListaD* li, int numeroNovo);

int insereListaOrdenada(ListaD* li, int numeroNovo);

int insereListaFinal(ListaD* li, int numeroNovo);



/*
### REMOÇÃO DA LISTA ###
*/

int removeListaInicio(ListaD* li);

int removeListaQualquer(ListaD* li, int numeroASerRemovido);

int removeListaFinal(ListaD* li);



/*
### CONSULTA NA LISTA ###
*/

int consultaListaPosicao(ListaD* li, int posicaoInformada, int *numeroConsultado);

int consultaListaDlemento(ListaD* li, int numeroInformado, int *posicaoConsultada);

int imprimeLista(ListaD* li);



#endif // LISTASEQUENCIALDINAMICA_H_INCLUDED
