#include <stdio.h>

int main(){

    /*
    int num1;
    int num2;

    printf("Inserisci un numero: ");
    scanf("%d",&num1);

    printf("Inserisci un altro numero:");
    scanf("%d",&num2);
    
    int somma;
    somma=num1+num2;

    int media;

    media=somma/2;
    printf("La media dei due numeri e': %d",media);
    */

    
    //dato un numero intero, positivo n, stampare i numeri primi da 2 a n

    int n;
    int prim;
    int c=2;
    int lista;
    printf("Inserisci un numero: ");
    scanf("%d",&n);

    if(n>0){

         while(c<=n){

            if(c/c==1 && c/1==c){

                lista=c;
                printf("%d",lista);
                c++;
            }
            else{
                c++;
            }
            
        }
    }

   



}