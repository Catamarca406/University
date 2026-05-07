#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;

}node;

node init(node* list){
    node l;
    list->val=0;
    list->next=l;

    return list;
}

node insert(node* list, int pos, int val){
    int i=0;
    do{
        if(i+1==pos){
            node *n =malloc(sizeof(node));
            node *l1;

            l1=list->next;
            list->next=n;
            n->next=l1;
            n->val=val;
            break;
        }
        list=list->next;
        i++;
    }while(list->next != NULL)
}

node pop(node *list){
    node *p;
    while(list->next!= NULL){
        
    }
}


int main(){


}