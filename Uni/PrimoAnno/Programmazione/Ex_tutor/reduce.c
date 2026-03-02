#include <stdio.h>
#include <stdlib.h>

char *reduce(char *array, int n){



char *copy;
copy=malloc((n+1)*sizeof(char));

    int i=0;
    int j=0;
    while(array[i]!='\0'){
        if ((array[i]>='a'&& array[i]<='z') || (array[i]>='A' && array[i]<='Z')){
            copy[j]=array[i];
            i++;
            j++;
        }
        else
            i++;
    }

    copy[n+1]='\0';

    
return copy;

}

int main(){

    char str[] = {'a','k','0','$','|',',',',','-','o','G','*'};
    
    int lenA=0;
    while(str[lenA]!='\0'){
        lenA++;
    }

    char *risultato=reduce(str,lenA);

    for(int i=0;i<lenA-1;i++){
        printf("%c",risultato[i]);
    }
    printf("%c\n",risultato[lenA]);
}