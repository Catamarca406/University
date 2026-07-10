#include <stdio.h>
#include <string.h>
//Conto il numero max di lettere consecutive

int main(){
    char s[] = "programmaaaa stringa";   
    int count=0;
    int temp=0;
    int j=1;
    for(int i=0; i<strlen(s);i++,j++){  
            if(s[i]==s[j] && s[j]!="\0"){
                count++;
                temp=count;
            }            
        }
        printf("%d\n",count);
    }
    
