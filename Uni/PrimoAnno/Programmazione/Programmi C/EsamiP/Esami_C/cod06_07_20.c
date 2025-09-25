/*Progettare una funzione che rimuove da una stringa a in input tutti i caratteri che non sono in ordine
lessicografico con i precedenti a partire dal primo simbolo. Dopo l'operazione a risulterà ordinata
lessicograficamente.

Esempio: Sia a[] = "ddabeceffgfh", la funzione deve modificare a in modo che essa rappresenti la
stringa "ddeeffgh".*/
#include <stdio.h>
#include <stdlib.h>

void rimuovi_non_ordinati(char *a)
{
    int lenE = 0;
    while ((a[lenE]) != '\0')
    {
        lenE++;
    }
    char *b;
    b = malloc((lenE+1) * sizeof(char));

    int j = 1;
    int c = 0;

    for (int i = 0; i < lenE; i++)
    {
        if (a[i] >= a[j] && a[j] != '\0')
        {
            b[c] = a[i];
            j = i;
            c++;
        }
    }
    b[c] = '\0';

    b=realloc(b,c*sizeof(char));

    printf("[");
    for (int i = 0; i < lenE; i++)
    {
        printf("%c", b[i]);
    }
    printf("]\n");
}

int main()
{
    char esempio[] = "ddabeceffgfh";
    rimuovi_non_ordinati(esempio);


    //Costo temporale: O(n)
    //Costo spaziale: O(n)
}


