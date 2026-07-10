#include <stdio.h>
#include <stdlib.h>

typedef struct vector
{
    int cap;   // capacità del vettore senza riallocare
    int len;   // quanti elementi sono stati inseriti
    int *data; // puntatore all'array
} vector;

vector *vector_init()
{
    vector *v = malloc(sizeof(vector)); // Alloca memoria per il vettore
    if (v == NULL)
    {
        return NULL; // errore di allocazione, malloc andata male.
    }
    v->cap = 0;     // v accede ai campi di una struct attraverso un puntatore
    v->len = 0;     // è il numero di elementi effetivamente presenti nell'array
    v->data = NULL; // v punta ad un array dinamico di interi, ha l'indirizzo dove sono memorizzati i dati
    return v;
}

int vector_append(vector *v, int elem)
{
    if (v->len == v->cap)   //se len=capacità --> aumento la capacità
    {
        v->data = realloc(v->data, 2 * (v->cap + 1) * sizeof(int)); // 2*(v->cap +1) nel caso in cui len=0=cap, 2*0=0
    }
    if (v->data == NULL)
    {
        return -1; // verifico che l'array non sia vuoto
    }
    v->data[v->len] = elem;   //posizione l'elemento in ultima posizione (v->len)
    v->len++;
    return 0;
}

int vector_search(vector *v, int elem)
{
    if (v->data == NULL)
    {
        return -1; // errore: vettore non valido
    }

    for (int i = 0; i < v->len; i++)
    {
        if (v->data[i] == elem)
        {
            return i; // ritorno l'indice
            break; //elemento trovato
        }
    }
    return -1; // valore non trovato
}

int vector_delete(vector *v, int elem)
{
    if (v->data == NULL)
    {
        return -1;
    }
    int pos = 0;
    
    pos=vector_search(v, elem);

    if (pos == -1)
    {
        return -1;
    }

    for (pos; pos < v->len; pos++)
    { // shift degli elementi
        v->data[pos] = v->data[pos + 1];
    }

    v->len--; // decremento la lunghezza
    if (v->cap >= v->len * 4)
    {
        v->data = realloc(v->data, v->cap / 2 * sizeof(int));
        v->cap = v->cap / 2;
    }
    if (v->data == NULL)
    {
        return -1; // realloc fallita
    }

    return 0; // successo
}

int vector_insert(vector *v, int elem, int index)
{
    if(index >= v->len){
        return -1;
    }
    vector_append(v, elem);
    
    for (int i = v->len - 1; i >= index; i--)
    {
        v->data[i+ 1] = v->data[i];
    }
    v->data[index] = elem;
    return 0;
}

void vector_print(vector *v){
    printf("[ ");
    for (int i = 0; i < v->len - 1; i++)
    {
        printf("%d, ", v->data[i]);
    }
    printf("%d ]\n", v->data[v->len - 1]);
}

void vector_free(vector *v){
    free(v->data);  //libero il vettore in memoria

    free(v);       //libero l'intera struct 
}



// int main(){
//     vector *v = vector_init();
//     for (int i = 0; i < 10; i++)
//     {
//         vector_append(v, i + 1);
//     }
//     vector_print(v);
//     vector_delete(v, 8);
//     vector_print(v);
//     vector_insert(v, 8, 7);
//     vector_insert(v, 100, 0);
//     vector_print(v);
//     vector_free(v);
// }