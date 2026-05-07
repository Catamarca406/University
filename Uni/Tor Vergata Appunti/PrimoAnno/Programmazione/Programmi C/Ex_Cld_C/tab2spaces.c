#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tab2spaces(char *a, int s){
    
    if(s==0){
        return a;
    }

    int lenA=0;
    int count_ts=0;

    for(int i=0;a[i]!='\0';i++){
        lenA++;
        if(a[i]=='\t'){
            count_ts++;
        }
    }

    if(count_ts==0){
        return a;
    }


    int lenB=(lenA-count_ts)+(count_ts*s);
    char* b;
    b=malloc((lenB+1)*(sizeof(char)));

    int k=0;

    for(int i=0;i<lenA;i++){
        if(a[i]=='\t'){
            for(int j=0;j<s;j++){
                b[k]=' ';
                k++;
            }
        }
        else{
            b[k]=a[i];
            k++;
        }
    }
    
    b[k]='\0';

    return b;

}


int main(void) {

    char *a = malloc(50);

    a = strcpy(a, "Hello\tWorld\t!");
    a = realloc(a, strlen(a)+1);
    printf("Originale: \"%s\"\n", a);
    a = tab2spaces(a, 2);
    printf("Modificata: \"%s\"\n", a);
    return 0;

    free(a);
}

//Costo spaziale: O(n)
//Costo temporale: O(n*s)