#include <stdio.h>
#include <stdlib.h>

//Restituire il numero di elementi dell'array che sono >=k

int conta_maggiore(int *array, int n, int k){
    int occorrenze=0;

    for(int i=0;i<n;i++){
        if(array[i]>=k){
            occorrenze++;
        }
    }

    return occorrenze;
    
}

int main(){
    int vettore[]={5,10,4,2,9,0,6};
    int lenV=sizeof(vettore)/sizeof(int);
    int k=5;

    int risultato=conta_maggiore(vettore,lenV,k);
    printf("numero di elementi uguali a:%d = %d\n",k,risultato);
}