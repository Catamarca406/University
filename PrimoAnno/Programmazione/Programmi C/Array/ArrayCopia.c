#include <stdio.h>
int main(){

    int vet[]={2,4,5,8};
    int lenV= sizeof(vet)/sizeof(vet[0]);
    int vet2[]={};
    int c=0;
    
    for(int i=0; i<lenV;i++){
        
        vet2[c]=vet[i];
        c++;
    }
    printf("Array originale:");             //Se non itero le posizioni anche nell'output dell'array non riesco a stampare tutto!!!!!!
    for(int i=0; i<lenV;i++){
        printf("%d", vet[i]);
    }
    printf("\n Array copia:");
    for(int i=0;i<lenV;i++){
        printf("%d",vet2[i]);
    }
}