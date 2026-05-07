#include <stdio.h>
#include <stdlib.h>

//Restituire un nuovo array che contiene l'array originale concatenato a se stesso 
int *duplica (int *array, int n){
    
    int lenV=2*n;
    int *vet2;
    vet2=malloc((lenV)*sizeof(int));
    

    for(int i=0;i<n;i++){
        vet2[i]=array[i];           //inserisco gli elementi di array in vet2
    }
    int j=n;

    for(int i=0;i<n;i++){
        vet2[j]=array[i];         //concateno vet2 agli elementi di array n-volte
        j++;
    }

    return vet2;
}

int main(){

int vet[]={1,2,3};
int n=3;

int *risultato=duplica(vet,n);

printf("[");
for(int i=0;i<5;i++){
    printf("%d,",risultato[i]);
}
printf("%d",risultato[5]);
printf("]\n");

}