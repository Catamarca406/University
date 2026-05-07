#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Nodo{
    int val;
    struct Nodo* next;
}typedef Nodo;

Nodo* creaNodo(int val){
    Nodo* new_node=(struct Nodo*)malloc(sizeof(struct Nodo));
    new_node->val=val;
    new_node->next=NULL;
    return new_node;
}



Nodo* crealista(int size){
    if(size<=0) return NULL;

    srand(time(NULL));
    int val=rand() %11;  
    Nodo* head=creaNodo(val);
    Nodo* current=head;

    for(int i=1;i<size;i++){    
        val = rand() % 11;
        current->next = creaNodo(val);       //creo il nuovo nodo
        current = current->next;            //incremento il "visualizzatore" di nodi
     }

    return head;
}


void stampalista(Nodo* head){
    Nodo* current=head;

    while(current!=NULL){
        printf("%d",current->val);
        current=current->next;
        if(current != NULL){
        printf("->");
        }
    } 
    printf("\n");   
}


int *Next_Greater_Nodes(Nodo* head,int arraySize){
    Nodo* current = head;

    int* a;
    a=malloc((arraySize)*sizeof(int));

    int j=0;
    int max=0;
    Nodo* p;

    while(current != NULL){
        p=current;
        max = p->val;
        while(p != NULL){
            if(max < p->val){
                max=p->val;
            }
            p=p->next;
        }
        
        if(current->val == max){
            a[j] = 0;
            j++;
        }
        else{
            a[j] = max;
            j++;
        }

        current=current->next;
    }
    
    return a;
}


int main(){
    
    int n=3;
    Nodo* lnk_l=crealista(n); 
    stampalista(lnk_l);
    int* result;
    result=Next_Greater_Nodes(lnk_l,n);
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d",result[i]);
        if(i<n-1){
            printf(",");
        }
    }
    printf("]");
    printf("\n");
}