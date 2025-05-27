#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//concatenare la stringa a e la b modificando a, n è la dim dell array che li contiene

char *strcatt(char *a, int n, char *b){
    int len_a=strlen(a);
    int len_b=strlen(b);
    if (n<len_a+len_b+1){ //+1 per il carattere terminante
        a="spazio insufficiente per a";
    }else
    {
    
    for(int i=0; i<len_b; i++){
        a[len_a++]=b[i];                //concateno b ad a
    }

    a[len_a]='\0';
    return a;
    }

}


int main(){
    char stringa1[]="stringa";
    char stringa2[]=" concatenata";
    int f;
    printf("metti in input la dim dell'array, che sia sufficiente:");
    scanf("%f", &f); //input f
    strcatt(stringa1,f,stringa2);
    printf("%s",stringa1);
    //non faccio free
}