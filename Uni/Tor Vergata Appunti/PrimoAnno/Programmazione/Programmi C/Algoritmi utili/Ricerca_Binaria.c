#include <stdio.h>

int ricerca_binaria(int vect[], int lenV,int choice){
    
    int high=lenV-1;
    int low=0;
   

    while(low<=high){               //ad ogni iterazione verifico se il vettore abbia almeno 1 elemento da verificare
        int mid=(high+low)/2;       //dichiaro ogni volta la posizione di mezzo

        if(choice==vect[mid]){      //verifico se la scelta si trovi al centro del vettore
            return mid;
        }
        else if(choice>vect[mid]){  //verifico se la scelta sia > del vettore in pos mid
            low=mid+1;             //aumento la parte bassa del vettore
        }
        else{                   //altrimenti...
            high= mid-1;        //diminuisco la parte alta del vettore
        }
    }
    return -1;      //ritorno -1 in caso di errore
}

int main(){ 
    //utile quando il vettore è già ordinato 
    
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};     //inizializzo il vettore
    int lenV = sizeof(vector)/sizeof(int);             //dichiaro la lunghezza del vettore
    int choice=6;                                     //scelgo il valore da cercare
    
    int result=ricerca_binaria(vector,lenV,choice);

    if(result!= -1){
        printf("Elemento trovato in posizione: %d\n",result);
    }
    else
        printf("Elemento non trovato\n");



    //Costo spaziale: O(1)
    //Costo temporale: O(log(n))

}