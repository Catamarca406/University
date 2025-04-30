#include <stdio.h>
int main(){
    //provo il bubble sort.
    int vet[]={3,2,8,-1};
    int lenV= sizeof(vet)/sizeof(vet[0]);
    int temp=0;

    for(int i=0; i<lenV-1;i++){
        for(int j=1; j<lenV; j++){
            if(vet[i]>vet[j]){  
                temp=vet[i];
                vet[i]=vet[j];
                vet[j]=temp;
            }
        }
    }

    printf("\n Array ordinato in modo crescente: ");
    for (int i=0; i<lenV; i++){
        printf("%d",vet[i]);
    }
}