#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

void printL(node *l){           //stampo la lista
    printf("[");
    while(l != NULL){
        printf("%d", l->val);
        l = l->next;

        if(l!=NULL){
            printf(",");
        }
    }
    printf("]\n");
}

void insert(node *l,int pos,int val){       //inserisco un valore in un nodo, in una determinata pos
    int i=0;
    do{
        if(i+1==pos){
            
            node *n=malloc(sizeof(node));
            node *l1;

            l1=l->next;
            l->next=n;
            n->next=l1;
            n->val=val;
            break;
        }
        l=l->next;
        i++;
        
    }while(l->next!=NULL);
}

void append(node *l,int val){       //inserisco un valore in ultima pos
    
    while(l->next!=NULL){
        l=l->next;
    }

    node *n;
    n=malloc(sizeof(node));
    n->val=val;
    n->next=NULL;
    l->next=n;
}   

int pop(node *l){           //cancello il valore in ultima pos
    node* p;
    while(l->next!=NULL){
        p = l;
        l=l->next;
    }
    p->next=0;
    int n=l->val;
    free(l);
    return n;
}

void main(){
    node n;         //creo un nodo
    n.val=29;       //inizializzo il nodo con val=29
    n.next=0;       
    insert(&n,1,10);
    append(&n,15);
    append(&n,89);
    append(&n,53);
    printL(&n);
    printf("Pop: %d\n",pop(&n));
    printL(&n);

}