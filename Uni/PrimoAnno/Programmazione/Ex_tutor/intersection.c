#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *intersection(char str1[],char str2[]){

    int lenS1=strlen(str1);
    int lenS2=strlen(str2);

    char *intersec;
    intersec=malloc((lenS1+lenS2)*sizeof(char));

    int k=0;
    for(int j=0;j<lenS1;j++){
        for(int i=0;i<lenS2;i++){
            if(str1[j]==str2[i]){
                intersec[k]=str1[j];
                k++;
                break;
            }
            
        }
    }    

    intersec[k]='\0';

    return intersec;

}

int main(){

    char str1[]="mare";
    char str2[]="marmmte";


    char *risultato=intersection(str1,str2);

    int lenR=strlen(risultato);
    
    for(int i=0;i<lenR;i++){
        printf("%c",risultato[i]);
    }
    printf("%c\n",risultato[lenR]);
}