//Dato un array di caratteri restituire una stringa contenente solamente i caratteri compresi tra aA-zZ
#include <stdio.h>
#include <stdlib.h>


char* reduce(char* array, int n){

    char* n_array;
    n_array=malloc(n*sizeof(char));
    int j=0;

    for(int i=0;i<n;i++){
        if((array[i]>='a' && array[i]<='z')||((array[i]>='A' && array[i]<='Z'))){
            n_array[j]=array[i];
            j++;
        }
    }
    n_array=realloc(n_array,j*sizeof(char));
    n_array[j]='\0';
    return n_array;

}



int main(){
    char prova [] = "A122132421w4nf lo perZCN12491";
    int lenP=0;

    while(prova[lenP]!='\0'){
        lenP++;
    }
    char* risultato=reduce(prova,lenP);

    printf("Stringa prima: %s\n",prova);
    printf("Stringa dopo: %s\n",risultato);

}