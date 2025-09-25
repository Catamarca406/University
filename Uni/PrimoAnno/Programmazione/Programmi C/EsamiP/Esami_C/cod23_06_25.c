#include <stdio.h>
#include <stdlib.h>

float* inserisci_media (float* a,int n){
    
    float max;
    float somma,media=0;
    float mag,min=0;
    int j=1;

    for(int i=0;i<n;i++){               //trovo la distanza massima
        if(a[j]-a[i]>max){
            max=a[i]-a[j];
            mag=a[i];
            min=a[j];
            j++;
        }
    }

    somma=mag+min;
    media=somma/2;

    float temp=0;
    a=realloc(a,(n+1)*sizeof(float));     //faccio l'append della media
    a[n]=media;

    for(int i=0;i<n;i++){               //inserisco il valore in una posizione casuale, ordinando nuovamente l'array
        if(a[i]<a[j]){
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            j++;
        }
    }
    return a;
    
}

int main(){
    float* a=malloc(sizeof(3)*sizeof(float));
    a[0]=31.4;
    a[1]=42.5;
    a[2]=61.9;
    int lenA=3;
    float* arr =inserisci_media(a,lenA);
    
    printf("[");
    for(int i=0;i<lenA+1;i++){
        printf("%f, ",arr[i]);
    }
    printf("]\n");
    

}
   
    

