#include <stdio.h>
int main(){

    /*int vet[]={1,2,3,4};
    int lenV= sizeof(vet)/sizeof(vet[0]);
    int vet2[lenV];
    int c=0;
    for(int i=lenV-1; i>=0;i--){
        vet2[c]=vet[i];
        c++;
    }
    printf("Il vettore al contrario e':");
    for(int i=0; i<lenV;i++){
        printf("%d ", vet2[i]);
    }
    */

    //Ottimizzato
    int vet[]={1,2,3,4};
    int lenV=sizeof(vet)/sizeof(vet[0]);
    int j=lenV-1;
    int i=0;
    int temp=0;
    while (i<j)
    {
        temp=vet[j];
        vet[j]=vet[i];
        vet[i]=temp;
        i++;
        j--;
    }
    printf("Il vettore al contrario e':");
    for(int i=0; i<lenV;i++){
        printf("%d ", vet[i]);
    }
}
