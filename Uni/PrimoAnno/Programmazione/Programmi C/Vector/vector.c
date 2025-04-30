#include <stdio.h>


typedef struct vector{
    int cap;   // capacità del vettore senza riallocare
    int len;   // quanti elementi sono stati inseriti
    int *data; // puntatore all'array
}vector;

vector *vector_init() {
    vector *v = malloc(sizeof(vector));  // Alloca memoria per il vettore
    if (v == NULL) {
        return NULL; // errore di allocazione, malloc andata male.
    }
    v->cap = 0;        // v->cap v accede ai campi di una struct attraverso un puntatore
    v->len = 0;       // è il numero di elementi effetivamente presenti nell'array
    v->data = NULL;  // v punta ad un array dinamico di interi, ha l'indirizzo dove sono memorizzati i dati
    return v;
}

void vector_append(vector *v, int elem){
    if(v->len == v->cap){
        v->data=realloc(v->data,2 * (v->cap + 1)*sizeof(int)); //2*(v->cap +1) nel caso in cui len=0=cap, 2*0=0
    }
    if(v->data == NULL){
        return NULL;        //verifico che l'array non sia vuoto
    }
    v->data[v->len] = elem;
    v->len++;
}

int vector_search(vector *v,int elem){
    if(v->data || v->data == NULL){
        return -1;  //errore: vettore non valido
    }

    for(int i=0;i<v->len;i++){
        if(v->data[i]==elem){
            return i;   //ritorno l'indice
        }
    }
    return -1; //valore non trovato
}


int vector_delete(vector *v, int elem){
    if(v->data == NULL){
        return -1;
    }
    int flag=0;
    int pos=0;

    for(int i=0; i< v->len;i++){
        if(v->data[i]==elem){
            pos=i;
            flag=1;
            break;  //elemento trovato
        }
    }
    if(flag==0){
        return -1;
    }
    
    for(pos; pos < v->len ;pos++){          //shift degli elementi
        if(flag==1){
            v->data[pos]= v->data[pos+1];
             
        }
    }

    v->len--; //decremento la lunghezza
    v->cap--; //decremento la capacità
    v->data=realloc(v->data, v->cap* sizeof(int));
    if(v->data == NULL && v->cap>0){
        return -1;  //realloc fallita
    }

    return 0; //successo
    
    
}

void vector_insert(vector *v, int elem, int index){
    if(v->len > v->cap){
        return -1;
    }
        for(int i=0; i<v->len;i++){
                
            v->data[index]=elem;

        }

    }
    
