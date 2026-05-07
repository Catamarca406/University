#include <stdio.h>
int main(){
    //Somma dei valori in un array
    int array[10];
    int somma=0;
    int lenA=sizeof(array)/sizeof(array[0]);


    printf("Inserisci 10 numeri:\n");
    for(int i=0;i<10;i++){
        scanf("%d", &array[i]);
    }

    for(int i=0;i<lenA;i++){
        somma+=array[i];
    }
    
    printf("La somma del vettore vale: %d",somma);
}