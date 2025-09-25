#include <stdio.h>
#include <stdlib.h>

//Data una stringa, restituire la lunghezza massima di una sequenza di '1'

int max_len(char* stringa){

int lenS=0;    

    while(stringa[lenS]!='\0'){       //calcolo la lunghezza della stringa
        lenS++;
    }

    int j=0;
    int *prova;
    prova=malloc(lenS*sizeof(int)); //alloco spazio per la stringa

    int c=0;  
    int lenP=1;  
    for(int i=0;i<lenS;i++){
        if(stringa[i]=='1'){
            c++;
        }
        else if(stringa[i]!='1'){
            prova[j]=c;
            j++;
            c=0;
            lenP=j;
        }
    }
    prova[lenP]=c;
    

    int max=prova[0];
    for (int i=1;i<=lenP;i++){
        if(max<=prova[i]){
            max=prova[i];
        }
    }
    
    return max;

}

int main(){
char input[]="110111";
int risultato=max_len(input);

printf("%d\n",risultato);


}

//Complessità: Spaziale= O(n), Temporale= O(n)