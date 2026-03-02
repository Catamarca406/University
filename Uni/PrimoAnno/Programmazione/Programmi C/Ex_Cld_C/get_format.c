#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *get_format(char *a){
    
    int lenA=strlen(a);

    for(int i=0;i<lenA;i++){
        if (a[i+1] == ';'){
            if (a[i] %2 == 0){
                a[i]='p';
            }
            else
                a[i]='d';
        }
    }

    return a;
}


int main(){
    
    char a[] = "7;90;0;123;8;4";
    char* result;

    result=get_format(a);
    printf("%s\n",result);

    free(result);
}