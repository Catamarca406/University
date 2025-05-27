#include <stdio.h>

typedef struct node{
    int val;
    node *next;

}node;

node init(int val){
    node *nd=malloc(sizeof(node));
    if(nd==NULL){
        printf("Errore nell'inizializzazione");
        return;
    }
    nd->val=val;
    nd->next=NULL;
}


