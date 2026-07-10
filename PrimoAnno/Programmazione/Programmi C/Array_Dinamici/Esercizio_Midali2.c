#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Allocare dinamicamente un array di interi, assegnare valori e deallocarlo
int main(){
int *vettore;       //alloco un puntatore ad una memoria casuale
int lenV=5;
srand(time(NULL));

vettore=malloc(lenV*sizeof(int));      //alloco lenV-spazi di memoria

if(vettore == NULL){
    printf("Errore nell'allocazione della meomoria");
}

for(int i=0;i<lenV;i++){
    vettore[i]=rand() % 21;
}

printf("[");
for(int i=0;i<lenV-1;i++){
    printf("%d,",vettore[i]);
}
printf("%d",vettore[lenV-1]);
printf("]\n");

free(vettore);
printf("Memoria deallocata\n");
}
