#include <stdio.h>
#include <stdlib.h>

char *banner_x(int n,int i){
    char *array = malloc((n+1));

    for (int j=0;j<n;j++){
        if (j==i || j==n-1-i){
            array[j]='*';
        }else{
            array[j]=' ';
        }
    }
    array[n]='\0';
    return array;
}




int main(){

    int valore_n=7; //maggiore uguale a 3 e dispari
    int valore_i=1;
    char *risultato = banner_x(valore_n,valore_i);
    printf("%s", risultato);
    free(risultato);
}
