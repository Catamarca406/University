#include <stdio.h>
#include <stdlib.h>


char *prefix(char *a, int n){
    int lenA=0;

    while(a[lenA]!='\0'){
        lenA++;
    }
    

    if(lenA==0 || n<0){
        return NULL;
    }

    if(n>lenA){
        char* cpy;
        cpy=malloc((lenA+1)*sizeof(char));

        for(int i=0;i<lenA;i++){
            cpy[i]=a[i];

        }
        cpy[lenA]='\0';

        return cpy;
    }
    

    char* prfx;
    prfx=malloc((n+1)*sizeof(char));

    for(int i=0;i<n;i++){
        prfx[i]=a[i];
    }
    prfx[n]='\0';
    return prfx;

}



int main(){

char a[] ="12345678910";
int n=2;
char * result=prefix(a,n);

if(result != NULL){
    printf("%s\n",result);
    free(result);
}
else{
    prinf("NULL\n");
}

}

//Costo spaziale: O(n)
//Costo temporale: O(n)