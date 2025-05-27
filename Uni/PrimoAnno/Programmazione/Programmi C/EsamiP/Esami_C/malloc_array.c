#include <stdio.h>
#include <stdlib.h>
/*
Scrivi un programma in C che:

    Chieda all'utente di inserire il numero di elementi che desidera memorizzare.
    Usi malloc per allocare dinamicamente memoria per un array di interi.
    Consenta all'utente di inserire i valori dell'array.
    Stampi tutti i valori inseriti.

*/

int main(){
    int f;
     // Stampare la richiesta all'utente
    printf("Quanti elementi vorresti memorizzare? ");
    scanf("%d", &f);
    int *array = malloc(f*sizeof(int)); //ALLOCARE MEMORIA DINAMICAMENTE SI FA IN QUESTO MODO PER UN ARRAY, NON USARE []
    for(int i=0; i<f; i++){
        printf("Inserisci il valore dentro l'array, stai a %d su %d: ", i+1, f);  //UTILIZZO CORRETTO DEL PRINF CON DUE VALORI, PRIMA LA STRINGA E POI LE VAR
        scanf("%d", &array[i]);
    }
    printf("Array finale:");
    for (int i=0; i<f; i++){
        printf("%d", array[i]);
        printf(",");
    }
}