#include <stdlib.h>
#include <stdio.h>


//allocare dinamicamente una stringa, assegnare un valore e deallocarla

int main(){

    char *stringa;
    char stringa2[]="ProVa1";
    int lenS=0;

    while(stringa2[lenS]!='\0'){
        lenS++;
    }

    stringa=malloc(lenS*sizeof(char));     //alloco n-spazi * il peso in byte di un carattere
    
    if(stringa==NULL){
        printf("allocazione non andata a buon fine");
    }
    
    for(int i=0; i<lenS;i++){
        stringa[i]=stringa2[i];
    }
    stringa[lenS]='\0';

    printf("%s\n",stringa);

    free(stringa);
    printf("Memoria deallocata\n");



}
