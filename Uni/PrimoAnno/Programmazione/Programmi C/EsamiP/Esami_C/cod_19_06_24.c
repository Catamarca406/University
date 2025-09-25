#include <stdio.h>
#include <stdlib.h>

/*
Si scriva una funzione avente il seguente prototipo:
char *prefix(char *a, int n);
dove a è una stringa.
La funzione deve ritornare una nuova stringa contenente i primi n caratteri di a.
Nel caso in cui n sia maggiore della lunghezza di a , la stringa deve ritornare una copia di a.
*/
int get_len(char *a)
{
    int lenA = 0;
    while (a[lenA] != '\0')
    {
        lenA++;
    }
    return lenA;
}

char *prefix(char *a, int n)
{
    int lenA = 0;
    lenA = get_len(a);

    if (n > lenA)
    {   
        char *b; 
        b = malloc((lenA + 1) * sizeof(char));

        for(int i=0;i<lenA;i++){
            b[i]=a[i];
        }
        b[lenA]='\0';
        return b;
    }
    else
    {
        char *b;                             //creo la nuova stringa per inserire i primi n-caratteri di a
        b = malloc((n + 1) * sizeof(char));  //faccio n+1 per inserire anche il carattere di fine stringa ('\0')  

        for (int i = 0; i < n; i++)
        {
            b[i] = a[i];
        }

        b[n] = '\0';

        return b;
    }
}

int main()
{
    char string[] = "sto andando in ufficio";
    int n =3;
    char* new_string;
    new_string=prefix(string,n);
    printf("%s",new_string);
    printf("\n");
}