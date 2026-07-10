#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Dato un array di caratteri restituire una stringa contenente solamente i caratteri tra aA-zZ

char *reduce(char *array, int n){

    int count=0;

    for(int i=0;i<n;i++){           //mi conto quanti elementi ci sono nella stringa
       
        if((array[i]>='A' && array[i]<='Z') || (array[i]>='a' && array[i]<='z')){           
            count++;
        }
        
    }

    char * n_array;
    n_array=malloc((count+1)*sizeof(char));     //alloco memoria in base a quanti elementi ho in stringa

    if(n_array==NULL){          //verifico se l'allocazione sia andata a buon fine
        printf("Allocazione della memoria fallita");
    }


    int j=0;        //inizializzo un nuovo iteratore, altrimenti avrei errori nel assegnare gli elementi da array a n_array
    for(int i=0;i<n;i++){  //creo la nuova stringa con solo gli elementi richiesti

       if((array[i]>='A' && array[i]<='Z') || (array[i]>='a' && array[i]<='z')){           
            n_array[j]=array[i];
            j++;
        }
    }

    n_array[j]='\0';        //inserisco di nuovo il carattere di fine stringa

    return n_array;
}


int main(){

    char prova[]="Pro6.va3_51A.b0K";
    int lenP=0;
    
    while(prova[lenP]!='\0'){
        lenP++;
    }
    
    printf("%s\n",reduce(prova,lenP));
} 