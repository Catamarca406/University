#include <stdio.h>
void main(){
    /*//somma in un vettore 
    int vect[] = {1,2,3,4,5,6};
    int somma=0;
    for(int i=0;i<6;i++)
    {
        somma+=vect[i];
    }
    printf("%d\n", somma);
    */

    /* //massimo in un vettore
    int num1=0;
    int vettore[]={50,-10,325,4,12,130};

    for(int i=0; i<(sizeof(vettore)/sizeof(vettore[0])); i++){      // sizeof(vettore)/sizeof(vettore[0]) = totale di byte / singolo valore di byte = num valori dell'array
        if(num1<vettore[i]){
            num1=vettore[i];
        } 
    }
    printf("%d\n",num1);
    */

   
    int vettore[]={-20,4,56,21,-1,5,-33};
    int num=vettore[0];
    int lenV = sizeof(vettore)/ sizeof(vettore[0]);
    
    for(int i=0; i<lenV;i++){
        if(num>vettore[i]){
            num=vettore[i];
        }
        else {
            
        }
    }
    printf("%d\n", num);
    

}