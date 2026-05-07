#include <stdio.h>
int main(){
    int vet[]={2,30,25,10};
    int lenV = sizeof(vet)/sizeof(vet[0]);
    int c=0;
    int b=0;
    for(int i=0; i<lenV;i++){
        if(vet[i]%2 == 0){
            c++;
        }
        else if(vet[i]%2 != 0){
            b++;
        }
    }
    printf("I numeri pari sono: %d \n", c);
    printf("I numeri dispari sono: %d", b);
}