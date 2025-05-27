#include <stdio.h>
#include <stdlib.h>


char *banner(int n, int s){ //s sarebbe la riga selezionata e n la grandezza max della x
    char *stringa = malloc((n+1));
    for(int i=0; i<=n; i++){
        //ad sarebbe asterisco destra che si ottiene sottraendo alla lunghezza la riga scelta
        if(i==s || i==(n-s)){
            stringa[i]='*';
            
        }else{
            stringa[i]='-';
        }
    }
    stringa[n]='\0';
    return stringa;
}
int main(){
    int n=7 ;
    int i=0;
    char *result=banner(n,i);
    printf("%s", result);
    free (result);
}
//fatto un report del file dei problemi che ho avuto con le stringhe e la funzione
// ella cartella università/problemi riscontrat0
