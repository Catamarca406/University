#include <stdio.h>
#include <stdlib.h>

/*
Scrivere una funzione che prenda in input un array di float e restituisca una sequenza ordinata delle posizioni dei massimi
nell'array.
La sequenza di output deve essere rappresentata tramite la struttura dati int_array , definita come segue.

struct int_array {
int dim;
int *v;
}
typedef struct int_array int_array;

Il campo v rappresenta un array di dim interi. La funzione da implementare deve avere il seguente prototipo
int_array pos_max(float *a, int n)
dove a è l'array ed n la sua dimensione.
*/

typedef struct int_array
{
    int dim;
    int *v;
} int_array;

void int_array_print(int_array *arr){
    printf("[");
    size_t i;
    for (i = 0; i < arr->dim - 1; i++)
    {
        printf("%d, ", arr->v[i]);
    }
    printf("%d] \n", arr->v[i]);
}

int_array pos_max(float *a, int n)
{
    float max = a[0];

    
    for (int i = 1; i < n; i++)        //cerco il massimo assoluto 
    {
        if (max <= a[i])
        {
            max = a[i];
        }
    }
    printf("Max: %0.2f\n", max);
    
    int n_max = 0;
    
    for (int i=0; i < n; i++)     // cerco le copie dei massimi assoluti
    {
        if (a[i] == max)
        {
            n_max++;
        }
    }
    
    
    int_array b = {
        .dim = n_max,
        .v = malloc(sizeof(int) * n_max)
    };
    
    int j = 0;
    for (int i = 0; i < n; i++)     
    { 
        if (a[i] == max)
        {
            b.v[j] = i;
            j++;
        }
    }

    return b;
}

int main()
{
    float a[] = {4.5, 8.9, 1.0, 7.7, 8.9};
    int lenA = sizeof(a) / sizeof(float);
    int_array max_pos = pos_max(a, lenA);
    int_array_print(&max_pos);
}