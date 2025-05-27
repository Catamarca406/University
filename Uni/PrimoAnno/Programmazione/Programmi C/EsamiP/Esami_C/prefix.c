//funzione char *prefix(char *a, int n); La funzione ritorna una nuova stringa contenente i primi
//n valori di a, nel caso in cui n sia maggiore della lunghezza di a, la stringa deve ritornare
//una copia di a

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *prefix(char *a, int n){
    int len_a=strlen(a);
    char *stringa2;
    if(n>len_a){ //faccio una copia
        stringa2=malloc(len_a+1);
        for (int i=0; i<len_a; i++){
            stringa2[i] = a[i];
        }
        stringa2[len_a]='\0';
        return stringa2;
    }else{  //copiamo i primi n caratteri e poi chiudiamo
        stringa2=malloc(n+1);
        for (int i=0; i<n; i++){
            stringa2[i]=a[i];
        }
        stringa2[n]='\0';
        return stringa2;
    }

}
int main(){
    int n=3;
    char *stringa="buongiorno";
    char *result = prefix(stringa, n);
    printf("%s",result);
    free(result);
}