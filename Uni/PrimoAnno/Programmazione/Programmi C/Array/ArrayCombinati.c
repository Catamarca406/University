#include <stdio.h>

int main(){
    //combina due array e metti in output i valori alternati

    /*
    //Versione con vettori statici
    int vet1[]={2,5,-1,8,19,10};
    int vet2[]={7,3,18,11,20,4};
    int lenV1=sizeof(vet1)/sizeof(vet1[0]);
    int lenV2=sizeof(vet2)/sizeof(vet2[0]);
    int lenV3=lenV1+lenV2;
    int vet3[lenV3]; //occhio alla dichiarazione del vettore, mai scrivere vet[]={};
    int c1=0;
    int c2=0;
    

    for(int i=0;i<lenV3;i++){
        if(i%2==0){
            vet3[i]=vet1[c1];
            c1++;
        }
        else{
            vet3[i]=vet2[c2];
            c2++;
        }
    }

    for(int i=0;i<lenV3;i++){
        printf("%d ,",vet3[i]);
    }
    
    /*Costi computazionali:
        Complessità temporale = o(n) / O(n)
        Complessità spaziale = o(n) / O(n)
    */
    
    //Versione con vettori dinamici
    
   
}


