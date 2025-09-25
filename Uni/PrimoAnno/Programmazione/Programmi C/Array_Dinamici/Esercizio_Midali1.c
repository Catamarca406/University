#include <stdio.h>
#include <stdlib.h>


//Allocare dinamicamente un intero, assegnare un valore e deallocarlo
int main(){

    int *vettore=malloc(sizeof(int));

    if(vettore == NULL){
        printf("Errore nell'allocazione della memoria");
    }
    *vettore=10;

    printf("%d\n",vettore[0]);
    free(vettore);
    printf("Memoria deallocata");
}



