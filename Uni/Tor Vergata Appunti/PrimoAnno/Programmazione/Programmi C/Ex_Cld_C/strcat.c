#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *str_cat(char *a, int n, char *b){
    
    int count_space=0;
    int lenB=0;
    while(b[lenB]!='\0'){
        lenB++;
    }

    int lenA=n;
    count_space=(lenA+lenB)+1;

    if(n<count_space){
        a=realloc(a,count_space);
    }

    int j=0;
    for(int i=lenA;i<count_space;i++){
        a[i]=b[j];
        j++;
    }
    a[count_space]='\0';
    
    return a;
}

int main(){


    char b[]= "world";
    char c[]="hello";
    char* a;
    
    int n=0;
    while(c[n]!='\0'){
        n++;
    }

    a=malloc((n+1)*sizeof(char));


    char *result;
    result=str_cat(a,n,b);
    printf("%s\n",result);

    free(a);
}

//Costo spaziale: O(n)
//Costo temporale: O(n)