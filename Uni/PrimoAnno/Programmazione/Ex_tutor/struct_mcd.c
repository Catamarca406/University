#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Nodo{
    int val;
    struct Nodo* next;
}Nodo;

Nodo* creaNodo(int val){
    struct Nodo* newNode = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

Nodo* creaLista(int len){
    if(len<=0) return NULL;
    srand(time(NULL));
    int val= rand() %151; 
    Nodo* head = creaNodo(val);
    Nodo* current = head;

    for(int i=1;i<len;i++){
        val = rand() % 151;
        current->next = creaNodo(val);
        current = current->next;        
    }

    return head;
}

int mcd(int a,int b){
    while(b!=0){
        int temp=b;
        b = a % b;
        a = temp;
    }
    return a;
}

Nodo* inserisciMCD(Nodo* head){
    Nodo* new_node;
    Nodo* current = head;

    while(current != NULL && current->next!=NULL){
        new_node=(Nodo*)malloc(sizeof(struct Nodo));
        if(new_node == NULL) return head;
        new_node->val=mcd(current->val,current->next->val);
        
        new_node->next=current->next;

        current->next = new_node;

        current=new_node->next;
    }

    return head;
}

void stampaLista(Nodo* head){
    Nodo* current = head;
    while(current!=NULL){
        printf("%d",current->val);
        current = current->next;
        if(current != NULL){
            printf("->");
        }
    }
    printf("\n");
}



int main(){
    
    int n=4;
    Nodo* list = creaLista(n);
    stampaLista(list);
    list = inserisciMCD(list);
    stampaLista(list);
}