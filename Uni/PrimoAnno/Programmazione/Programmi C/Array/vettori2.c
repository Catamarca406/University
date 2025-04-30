#include <stdio.h>
void main(){
    int num;
    //somma= m+n+o 
    //media = somma/3
    //media in un arra
    int vet[]={30,2,8,10};
    int lenV=sizeof(vet)/sizeof(vet[0]);
    int somma=0;
    float media;
    for(int i=0; i<lenV; i++){
        somma+=vet[i];
        media= (float) somma/lenV;
    }
    printf("%d\n",somma);
    printf("%0.2f\n",media);
}