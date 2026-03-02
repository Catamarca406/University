#include <stdio.h>
#include <stdlib.h>

char* banner_X(int n, int row){

    char* s;
    s=malloc((n+1)*sizeof(char));
    
    for(int i=0;i<n;i++){
        if(i==row || n-i-1==row){
            s[i]='*';
        }
        else
            s[i]='.';
    }
    s[n]='\0';

    return s;

}


int main(){
    char* result;
    
    //stampo solo una riga

    result=banner_X(7,2);
    printf("'%s'",result);
    printf("\n");


    //stampo tutta la X
    for(int i=0;i<=20;i++){
        result=banner_X(20,i);
        printf("'%s'",result);
        printf("\n");
    }

    free(result);
}