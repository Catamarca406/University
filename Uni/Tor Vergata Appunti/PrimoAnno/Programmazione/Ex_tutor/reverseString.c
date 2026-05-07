#include <stdio.h>
#include <stdlib.h>
    
    
    /*
    Data una stringa in input, scrivere una funzione C che modifichi 
    la stringa originale in modo da ottenere la stringa invertita

    La funzione deve avere il seguente prototipo: void reverse(char *str)
    */

char *reverse(char *str){
    int lenS=0;

    for (int i=0; str[i]!='\0' ;i++) 
    {
        lenS++;                 //calcolo la len della stringa iniziale per inizializzare la stringa di appoggio
    }
    
    char *copia;
    copia=malloc((lenS+1)*sizeof(char));

    int i=lenS;
    while(i>=0){
        copia[lenS-i]=str[i];
        i--;
    }
    copia[lenS+1]='\0';

   return copia;
}

int main(){

    char prova[]="123456";
    int lenS=0;

    for (int i=0; prova[i]!='\0' ;i++) 
    {
        lenS++;                 
    }

    char *risultato=reverse(prova);

    for(int i=0;i<=lenS-1;i++){
        printf("%c",risultato[i]);
    }
    printf("%c\n",risultato[lenS]);
   
}
