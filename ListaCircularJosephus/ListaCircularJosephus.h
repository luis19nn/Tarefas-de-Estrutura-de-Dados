#ifndef LISTACIRCULARJOSEPHUS_H_INCLUDED
#define LISTACIRCULARJOSEPHUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
### TYPEDEF DA LISTA ###
*/

typedef struct ED_LE* Lista;
typedef struct ED_LE Nodo;



/*
### CRIAÇÃO E LIBERAÇÃO DA LISTA ###
*/

Lista* criaLista();

void liberaLista(Lista* li);



/*
### INSERÇÃO NA LISTA ###
*/

int insereListaFinal(Lista* li, char nomeNovo);



/*
### IMPRESSÃO DA LISTA ###
*/

int imprimeLista(Lista* li);



/*
### FUNÇÕES DE JOSEPHUS ###
*/

void nomeSoldados(Lista *li);

void inicioContagem(Lista *li, char primeiroSoldado);

void contagem(Lista *li, int pular);



#endif // LISTACIRCULARJOSEPHUS_H_INCLUDED
