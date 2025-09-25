#include <stdio.h>
#include <stdlib.h>

/*
char *str_cat(char *a, int n, char *b);
dove a e b sono due stringhe e n è la dimensione dell'array contenente a .
La funzione deve concatenare b ad a , modificando a.
Restituisce la stringa a modificata.
*/

char *str_cat(char *a, int n, char *b){
    int lenB=0;
    while(b[lenB]!='\0'){
        lenB++;
    }   

    int lenAB=lenB+n;
    int j=n;
    a=realloc(a,lenAB);
    
    for(int i=0;i<lenB;i++){
            a[j]=b[i];
            j++;
    }
    a[lenAB]='\0';  

    return a;
}

int main(){
    char parola1[]="ciao";
    int lenA=(sizeof(parola1)/sizeof(char))-1;
    
    char parola2[]="mondo";
    int lenB=(sizeof(parola2)/sizeof(char))-1;

    char *a;
    a=malloc((lenA+1)*sizeof(char));
    for(int i=0; i<lenA; i++){
        a[i]=parola1[i];
    }
    a[lenA]='\0';

    char *b;
    b=malloc((lenB+1)*sizeof(char));
    for(int i=0; i<lenB; i++){
        b[i]=parola2[i];
    }
    b[lenB]='\0';
    
    char*c;
    int lenC=0;
    c=str_cat(a,lenA,b);

    while(c[lenC]!='\0'){
        lenC++;
    }

    for(int i=0;i<lenC;i++){
        printf("%c",c[i]);
    }
    printf("\n");
}

//costo Temporale: O(n)
//costo Spaziale:  O(n)