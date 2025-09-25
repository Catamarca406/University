#include <stdio.h>
#include <stdlib.h>

char *prefix(char *a, int n)
{
    int lenA = 0;

    while (a[lenA] != '\0')
    { // calcolo la len della stringa
        lenA++;
    }

    if (n <= lenA)
    { // verifico che la posizione a cui fermarsi sia inferiore alla len di a
        char *nstring = malloc(sizeof(char) * n);
        for (int i = 0; i < n; i++)
        {
            nstring[i] = a[i]; // copio a in una nuova stringa
        }
        return nstring; // ritorno la nuova stringa
    }
    else
    {                                               // se pos>len a ritorno una copia di a
        char *a_copy = malloc(sizeof(char) * lenA); // assegno la lunghezza della stringa a alla sua copia, dinamicamente

        for (int i = 0; i < lenA; i++)
        {
            a_copy[i] = a[i];
        }
        return a_copy;
    }
}

int main()
{
    char a[] = "prova_numero_1";
    int lenA = sizeof(a) / sizeof(char);
    int n = 10;
    char *b;
    b = prefix(a, n);

    printf("%s\n", b);
}