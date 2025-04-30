#include <stdio.h>
#include <string.h>
int main(){
    char s[] = "programma stringa";
    int count=0;

    for(int i=0; i<strlen(s);i++){
        for(int j=1; j<strlen(s); j++){
            if(s[j]==s[j+1]){
                count++;
                printf("%d",count);
            }            
        }
    }
   

    
}