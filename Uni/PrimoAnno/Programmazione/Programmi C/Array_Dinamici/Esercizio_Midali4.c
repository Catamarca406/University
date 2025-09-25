#include <stdio.h>
#include <stdlib.h>

//allocare dinamicamente una struttura, assegnare valori e deallocarla
typedef struct punto{
    int x;
    int y;
}pnt;

int main(){
    pnt *p;
    p=malloc(sizeof(pnt));
    if(p==NULL){
        printf("Errore nell'allocazione della memoria");
    }

    p->x=10;
    p->y=15;

    printf("(%d,%d)\n",p->x,p->y);

    free(p);
    printf("Memoria deallocata\n");



}