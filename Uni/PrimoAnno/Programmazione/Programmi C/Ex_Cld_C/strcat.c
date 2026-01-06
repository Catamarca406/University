#include <stdio.h>
#include <stdlib.h>


char *str_cat(char *a, int n, char *b){
    
    int count_space=0;
    int lenB=0;
    while(b[lenB]!='\0'){
        lenB++;
    }

    count_space=n-lenB;

    if()


}

int main(){

    char a[]= "hello";
    char b[]= "world";

    int n=0;

    while(a[n]!='\0'){
        n++;
    }

    char *result;
    result=str_cat(a,n,b);

}