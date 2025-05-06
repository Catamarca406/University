#include <stdio.h>
/*funzione void filtra che prende come campi puntatore ad a,b. 
Ricevo in input un array di 0 e 1, per ogni posizione di 1 deve passare la lettere della parola.
Gli array di 0 e 1 e quello di parole hanno stessa len */

void filtra(char *a,int *b){
    int lenA=sizeof(a)/sizeof(a[0]);
    int j=0;
    for(int i=0;i<lenA+1;i++){
        if(b[i]==1){
            a[j]=a[i];
            j++;
        }
    }
    a[j]='\0';

    }


int main(){
    char a[9]="algoritmo";
    int b[9]={1,0,0,1,1,1,0,0,1};
    int lenA=sizeof(a)/sizeof(a[0]);

    filtra(a,b);
    printf("La nuova stringa e': %s",a);
}


