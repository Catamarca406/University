#include <stdio.h>
#include <stdlib.h>

/*in un array dinamico posso: -Utilizzare Append
                              -Modificare i valori
                              -Eliminare i valori

                                                    */

struct lista_i
{
    int *a;
    int cap;
    int dim;
};
typedef struct lista_i lista_i; // dichiaro un'alias per la struct

lista_i init()
{
    lista_i lista_nuova = {NULL, 0, 0}; // inizializzo la nuova lista
    return lista_nuova;
}

lista_i append(lista_i L, int elem)
{
    if (L.dim == L.cap)
    {
        L.cap = 2 * (L.cap + 1);
        L.a = realloc(L.a, L.cap * sizeof(int));
    }
    L.a[L.dim] = elem;
    L.dim++;
    return L;
}

void print(lista_i L)
{
    printf("[");
    for (int i = 0; i < L.dim; i++)
    {
        printf("%d, ", L.a[i]);
    }
    printf("]\n");
}

lista_i pop(lista_i *L)
{
    if(L->dim==0){
        printf("Array vuoto");
    }
    int lastE = L->a[L->dim];
    L->dim--;
}

int main()
{
    int i = 0;
    lista_i L = init();
    for (i; i < 5; i++)
    {
        L = append(L, 6);
    }
    print(L);
}