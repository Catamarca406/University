#include <stdio.h>

/* a è una stinga definita o come array statico o come puntatore ad array dinamico
a contiene n interi separati da n-1 caratteri: ; 
La funzione deve modificare a sostituendo ad ogni intero il carattere p O d se pari o dispari,
deve ritornare il puntatore alla stringa modificata

*/

char *get_format(char *a){
    int lenA=0;
    int j=0;

    while(a[lenA]!= '\0'){          //calcolo la lunghezza di a
        lenA++;
    }

    for(int i=0; i<lenA;i++){       //quando trovo un ; lo inserisco in a[j], ricomincio la stringa
        
        if(a[i]==';'){
            a[j]=';';
            j++;
        }
        
        if(a[i+1]==';' || a[i+1]=='\0'){         //fino a che il valore successivo è uguale a ';' o '\0'
        
            if((a[i]-'0')%2==0){                //casto i caratteri con: a[i]-'0' e verifico quando è pari
                a[j]='p';
                j++;
            }
            else{
                a[j]='d';
                j++;

            }
                
                    
        }
    }  
    
    a[j]='\0';          //inserisco nuovamente il carattere di fine stringa
    return a;       //ritorno la stringa modificata
}
    



int main(){

    char a[]={"7;90;0;123;8;4"};

    
    char *b =get_format(a);   //carico la stringa in una stringa di appoggio 

    int lenB=0;
    while(b[lenB]!= '\0'){  //calcolo la lunghezza della nuova stringa
        lenB++;
    }

    printf("[");
    for(int i=0;i<lenB;i++){        
        printf("%c",b[i]);          //stampo i valori della nuova stringa
    }
    printf("]\n");

}