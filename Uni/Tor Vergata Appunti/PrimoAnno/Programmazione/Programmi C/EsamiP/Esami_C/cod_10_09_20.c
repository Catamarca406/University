/*
Progettare una funzione C che acquisisce l'input da terminale e termina non appena l'utente digita
una stringa che non rappresenta un intero. Durante il processo di acquisizione ogni intero digitato
deve essere inserito in fondo ad una lista inizialmente vuota. La funzione deve restituire la lista
creata.
I nodi della lista sono definiti dalla seguente struct:
struct nodo {
    int valore;
    struct nodo *succ;
    struct nodo *prec;
};
typedef struct nodo nodo;

dove succ e prec sono, rispettivamente, gli indirizzi del nodo che segue e del nodo che precede
quello in questione. Il campo succ dell'ultimo nodo ed il campo prec del primo nodo valgono
NULL.
*/
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valore;
    struct nodo *succ;
    struct nodo *prec;
};
typedef struct nodo nodo;

nodo *input_list()
{
}

nodo *init_list()
{
    nodo nd;
    nd.valore = 0;
    nd.prec = NULL;
    nd.succ = NULL;
}

int main()
{
    init_list();
    int valori[]={10,5,8,12,3,4};
}