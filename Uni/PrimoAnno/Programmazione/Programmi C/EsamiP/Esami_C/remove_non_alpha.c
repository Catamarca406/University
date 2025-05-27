#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
Si scriva una funzione che elimini da una stringa in input tutti i caratteri non alfabetici
*/
void remove_non_alpha(char *a){
    int len_a=strlen(a);
    int j=0;   //RICORDARSI SEMPRE DI INIZIALIZZARE J, CON UN VALORE COME ZERO  
    for(int i=0; i<len_a; i++){
        if(isalpha(a[i])){
            a[j++]=a[i];
        }

    }
    a[j]='\0';
    printf("%s",a);
}


int main(){

char stringa[]="-.-.12-.ciao";
remove_non_alpha(stringa);

}