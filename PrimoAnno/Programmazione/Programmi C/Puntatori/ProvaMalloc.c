#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main(){
    /* Sintassi di base: "tipo" *p = puntatore a "tipo"
                         &variabile = indirizzo in memoria di quella variabile
                         *p = &variabile = puntatore che punta all'indirizzo in memoria della variabile
    */
    /*
    int x=10;
    int *p=&x; // p punta all'indirizzo in memoria di x
    printf("%p, %p\n",p,&x);
    printf("%d", *p); // p punta alla memoria di x, con %d e *p faccio puntare al valore di x
    
}*/
   /* 
    void cambiaValori(int *p1, int *p2){
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        
    }
    int main(){
    int x=10, y=15;
    

    // int *p1 = &x; // p1 prende il valore di x
    // int *p2 = &y; // p2 prende il valore di y
    printf("Numeri prima del cambio:\n x = %d\n y = %d\n", x,y);
    cambiaValori(&x,&y);
    printf("Numeri dopo il cambio:\n x = %d\n y = %d\n", x,y);
    }
    */

    /*int main (){
        // Incremento di un numero usando un puntatore
        int x=9;
        int *p = &x;
        printf("%d", *p+1);

    }*/

    int main(){
        // Funzione per calcolare la lunghezza di una stringa usando puntatori
        
        char s []="hello world";
        char *p = &s[0];
        int c=0;    
        while(*p != "\0")
        {
            c++;  //conto lettera
            *p++; //incremento l'iteratore sulle lettere
        }
        printf("%d",c);
        

    }