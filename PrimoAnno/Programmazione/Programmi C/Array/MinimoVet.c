#include <stdio.h>
int main(){
    int vet[]={2,-40,1,-34};
    int lenV= sizeof(vet)/sizeof(vet[0]);
    int min=vet[0];
    int c=1;
    for(int i=1; i<lenV;i++){
      
        if(min>vet[i]){
            min=vet[i];
        }
        
    }
    printf("Il minimo e': %d",min);
}