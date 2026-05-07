#include <stdio.h>
/*int main(){
    //Somma di valori in un vettore

    int num=0;
    int array[10];
    int lenA=sizeof(array)/sizeof(array[0]);
    int somma=0;
    
    for(int i=0;i<10;i++){
        printf("Inserisci un numero intero:");
        scanf("%d",&num);
        array[i]=num;
    }

    for (int i=0;i<lenA;i++)
    {
        somma+=array[i];
    }
    
    printf("La somma del vettore e':%d ",somma);
}*/

/*int main(){
    //Massimo e minimo in un array

    int arr[]={10,5,3,18,22};
    int max= arr[0];
    int min=arr[0];
    int lenA=sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<lenA;i++){
        
        if(min>=arr[i]){
            min=arr[i];
        }

        if(max<=arr[i]){
            max=arr[i];
        }

    }
    printf("Il massimo e il minimo sono: %d e %d",max,min);
}*/


/*int arrPari(int arr[],int lenA){
    int c=0;

    for(int i=0;i<lenA;i++){
        if(arr[i]%2==0){
            c++;
        }
    }
    return c;
}
int main(){

    //funzione che prende in input un array e la sua dimensione, restituisce il numero di elementi pari
    int arr[]={10,4,2,3,7,9};
    int lenA = sizeof(arr)/sizeof(arr[0]);
    printf("I numeri pari nel vettore sono:%d",arrPari(arr,lenA));
    
}*/

/*int main(){
    //Dato un array ruota gli elementi al suo interno di N posizioni a destra
    int arr[]={2,8,5,3,1};
    int pos=2;
    int temp=0;
    
}*/


/*int main(){
    //Dato un array rimuovi tutti i duplicati

    int arr[]={10,22,5,19,8,4,22,10,5};
    int lenA = sizeof(arr)/sizeof(arr[0]);

    printf("Il vettore originale e':");
    for (int i=0; i<lenA;i++)
    {
        printf("%d",arr[i]);
    }
      
    for(int j=0;j<lenA;j++){

        for(int i=1;i<lenA;i++){
            if(arr[j]==arr[i]){
                arr[i]=0;
            }
        }
    }
    
    
    printf("Il vettore senza ripetizioni e':");
    for (int i=0; i<lenA;i++)
    {
        printf("%d",arr[i]);
    }
}*/



