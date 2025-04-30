#include <stdio.h>
//#include <stdbool.h>

int numero=100; //Provo la variabile globale
int main(){
    
    int num1=0,num2=0;
    printf("Inserisci un numero:");
    scanf("%d",&num1);
    printf("Inserisci un numero:");
    scanf("%d",&num2);
    

    int somma = num1+num2;      
    printf("La somma e': %d\n",somma,"\n"); 
    printf("Provo la variabile globale: %d\n", numero,"\n");
    

    /*int num1=0,num2=0;
    printf("Inserisci un numero:");
    scanf("%d",&num1);
    printf("Inserisci un numero:");
    scanf("%d",&num2);

    bool comparazione = (num1>=num2);
    printf("Il risultato è: %d\n", comparazione);
    */
}
