#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Allocare dinamicamente una matrice 2D di interi, assegnare valori e deallocarla
int main(){

    int **vettore;
    int cols=4;
    int rows=4;
    vettore=(int**)malloc(rows*sizeof(int*));
    
    if(vettore==NULL){
        printf("Errore nell'allocazione della memoria");
    }
    srand(time(NULL));

    for(int i=0;i<rows;i++){
        vettore[i]=malloc(cols*sizeof(int));
        if(vettore==NULL){
        printf("Errore nell'allocazione della memoria");
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            vettore[i][j]=rand() % 21;
        }
        printf("\n");
    }

     for(int j=0;j<rows;j++){
        for(int i=0;i<cols;i++){
            printf("%d,",vettore[i][j]);
        }
    }


    for(int i=0; i<rows;i++){
        free(vettore[i]);
    }
    free(vettore);

    printf("Memoria deallocata\n");
    
    }