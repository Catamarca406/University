// presa una stringa in upper case trasformala in lower case.
#include <stdio.h>
#include <string.h>
void main(){
    char parola [] = "ABOMINEVOLE";
    int lenS= sizeof(parola)/sizeof(parola[0]);
    for(int i=0; i<lenS;i++){

        /*if(parola[i]>64 && parola[i]<91){
            parola[i]=parola[i]+32;
        }
        */
       if(parola[i]=='E'){
        parola[i]=parola[i]-'A'+'a';
       }
    }
printf("%s\n",parola);
}
