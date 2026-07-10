#include <stdio.h>
#include <stdlib.h>

/*
Si scriva una funzione in C che riceva in input:
un array dinamico a di numeri in virgola mobile ( float ), ordinato in modo crescente,
un intero n che rappresenta la dimensione attuale dell’array,
e che inserisca nell’array un nuovo elemento con valore pari alla media aritmetica dei due elementi
consecutivi di a che presentano la massima distanza tra di loro. La funzione deve ritornare l'array
modificato.
La funzione dovrà avere il seguente prototipo

float* inserisci_media(float* a, n);
*/

float* inserisci_media(float* a, int n){
    float max_dist=0;
    float media_arit=0;
    int j=1;

    for(int i=0;i<n;i++){
        media_arit=(a[i]+a[j])/2;
        if(max_dist<=media_arit){
            max_dist=media_arit;
        }
        j++;
    }

    float temp=0;
    float elem=a[0];

    for(int i=1;i<n;i++){
        if(max_dist<elem){
            temp=a[i];
            a[i]=max_dist;
            max_dist=a[i];
        }
           
    }


    printf("%f",max_dist);
    printf("\n");
    return a;

}


int main(){
    float a[]={3.2 ,4.1 ,5.9 ,7.3 ,8.3 ,10.3};
    int n=sizeof(a)/sizeof(float);
    float *media;
    media=inserisci_media(a,n);

    printf("[");
    for(int i=0; i<n;i++){
        printf("%d,",media);
    }
    printf("]");
    printf("\n");

}