#include <stdio.h>
int main(){
    //Trovare il secondo minimo in un array
    int vet[]={3,2,-1,6};
    int lenV=sizeof(vet)/sizeof(vet[0]);
    int min=vet[0];
    int min2=0;
       for(int i=1; i<lenV;i++){
            if(min>vet[i]){
                min=vet[i];
            }
       }
       min2=min;
       for(int i=0; i<lenV;i++){
            if(min2<vet[i]){

            }
       }

       printf("Il primo minimo e': %d\n",min);
       //printf("Il secondo minimo e': %d", min2);

}