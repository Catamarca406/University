#include <stdio.h>
#include <stdlib.h>

//allocare dinamicamente un array di strutture, assegnare valori e deallocarlo
typedef struct punto{
    int x;
    int y;

}punto;

int main(){
    punto *p;
    int n=10;
    p=malloc(n*sizeof(punto));        /*alloco "punto"-byte n-volte, sizeof(struct) somma tutti i tipi 
                                      al suo interno e torna i byte sommati*/

    if(p==NULL){
        printf("Errore nell'allocazione della memoria");
    }

    for(int i=0;i<n;i++){
        p[i].x=i;
        p[i].y=i+i;
    }

    printf("[");
    for(int i=0;i<n;i++){
        printf("(%d,%d)",p[i].x,p[i].y);
    }
    printf("]\n");
    
    free(p);
    printf("Memoria deallocata\n");
}