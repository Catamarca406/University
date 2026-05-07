#include <stdio.h>

int main(){
    int vet[]={19,3,5,10,3,11};
    int *p=vet;
    int lenV =sizeof(vet)/sizeof(vet[0]);
    
    printf("%d,%p",*p,*(p+1));
//ex1 scrivi in un array n valori fino a che non scrivi -1: stampa
//ex2 combina due array e metti in output i valori alternati

}