#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeadaCircular.h"
#include "ListaEncadeadaCircular.c"

int main()
{
    Lista *li;

    int entrada;

    while (1) {
        printf("\n 1) Criar a lista encadeada circular");
        printf("\n 2) Liberar  lista encadeada circular");
        printf("\n 3) Inserir no inicio");
        printf("\n 4) Inserir no fim");
        printf("\n 5) Inserir no meio (ordenado)");
        printf("\n 6) Remover do inicio");
        printf("\n 7) Remover do fim");
        printf("\n 8) Remover do meio");
        printf("\n 9) Consultar pelo conteudo");
        printf("\n 10) Consultar pela posicao");
        printf("\n 11) Imprimir Lista dinamica");
        printf("\n 12) Sair");
        printf("\n\nOpcao: ");
        scanf("%d", &entrada);

        switch (entrada) {
            case 1:
                li = criaLista();

                if(li == NULL) {
                    printf("\nNao foi possivel alocar memoria para a estrutura!\n");
                    exit(0);
                } else {
                    printf("\nLista criada com sucesso!\n");
                }

                break;
            case 2:
                liberaLista(li);

                printf("\nA lista dinamica foi liberada!\n");

                break;
            case 3:
                insereLista_AuxiliarInterface(li, 0);

                break;
            case 4:
                insereLista_AuxiliarInterface(li, 1);

                break;
            case 5:
                insereLista_AuxiliarInterface(li, 2);

                break;
            case 6:
                removeLista_AuxiliarInterface(li, 0);

                break;
            case 7:
                removeLista_AuxiliarInterface(li, 1);

                break;
            case 8:
                removeLista_AuxiliarInterface(li, 2);

                break;
            case 9: ;
                int dadoInformado, posicaoConsultada;

                printf("\nQual numero voce deseja consultar para descobrir a sua posicao na lista?: ");
                scanf("%d", &dadoInformado);

                int liBuscaElemento = consultaListaElemento(li, dadoInformado, &posicaoConsultada);

                if (liBuscaElemento){
                    printf("\nA posicao do numero informado eh: %d\n", posicaoConsultada);
                } else {
                    printf("\nERRO AO BUSCAR! Numero informado nao consta na lista!\n");
                }

                break;
            case 10: ;
                int posicaoInformada, dadoConsultado;

                printf("\nQual posicao voce deseja consultar para descobrir o seu valor na lista?: ");
                scanf("%d", &posicaoInformada);

                int liBuscaPosicao = consultaListaPosicao(li, posicaoInformada, &dadoConsultado);

                if (liBuscaPosicao){
                    printf("\nA posicao do numero informado eh: %d\n", dadoConsultado);
                } else {
                    printf("\nERRO AO BUSCAR! Posicao informada nao consta na lista!\n");
                }

                break;
            case 11: ;
                int liImprimeLista = imprimeLista(li);

                if (!liImprimeLista)
                    printf("\nERRO AO IMPRIMIR! A lista esta vazia ou nao existe!\n");

                break;
            case 12:
                exit(0);
            default:
                printf("\nOpcao de menu invalida!\n");
        }
    }

    return 0;
}
