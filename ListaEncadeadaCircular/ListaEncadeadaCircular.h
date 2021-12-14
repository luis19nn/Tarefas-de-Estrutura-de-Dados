#ifndef LISTAENCADEADACIRCULAR_H_INCLUDED
#define LISTAENCADEADACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
### TYPEDEF DA LISTA ###
*/

typedef struct ED_LE* Lista;
typedef struct ED_LE Nodo;


/*
### FUNÇÕES AUXILIARES ###
*/

void insereLista_AuxiliarInterface(Lista* li, int inicioMeioFim);

void removeLista_AuxiliarInterface(Lista* li, int inicioMeioFim);



/*
### CRIAÇÃO E LIBERAÇÃO DA LISTA ###
*/

Lista* criaLista();

void liberaLista(Lista* li);



/*
### INFORMAÇÕES DA LISTA ###
*/

int tamanhoLista(Lista* li);

int listaCheia();

int listaVazia(Lista* li);



/*
### INSERÇÃO NA LISTA ###
*/

int insereListaInicio(Lista* li, int dadoNovo);

int insereListaOrdenada(Lista* li, int dadoNovo);

int insereListaFinal(Lista* li, int dadoNovo);



/*
### REMOÇÃO DA LISTA ###
*/

int removeListaInicio(Lista* li);

int removeListaQualquer(Lista* li, int dadoASerRemovido);

int removeListaFinal(Lista* li);



/*
### CONSULTA NA LISTA ###
*/

int consultaListaPosicao(Lista* li, int posicaoInformada, int *dadoConsultado);

int consultaListalemento(Lista* li, int dadoInformado, int *posicaoConsultada);

int imprimeLista(Lista* li);



#endif // LISTAENCADEADACIRCULAR_H_INCLUDED
