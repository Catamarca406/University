#include <stdio.h>
#include <stdlib.h>


char *tab2spaces(char *a, int s){
    int lenA=0;

    while(a[lenA]!='\0'){
        lenA++;
    }
    
    int conta_caratteri=0;
    for(int i=0;i<lenA;i++){
        if(a[i]=='\t'){
            conta_caratteri+=1;
            a[i]=s;
        }
    }
    

    return a;
}



int main(){
    char *a=malloc(50);
    char* output;
    output=tab2spaces(a,2);
    printf("%s",output);
}