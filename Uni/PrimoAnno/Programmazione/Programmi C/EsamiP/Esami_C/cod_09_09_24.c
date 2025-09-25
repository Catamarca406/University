#include <stdio.h>
#include <stdlib.h>

/*
Si scriva una funzione avente il seguente prototipo:

char *string_center(char *a, int w, char c);

La funzione deve ritornare una stringa di lunghezza w contenente una copia di a posizionata al
centro della stringa e circondata da caratteri c .
*/


char *string_center(char *a, int w, char c){   
    
    if(w%2!=0){
        return NULL;
    }
    
    int lenA=0;
    while(a[lenA]!='\0'){
        lenA++;
    }

    int sp_in=(w-lenA)/2;
    int sp_fi=(w-sp_in);

    char *new_a;
    new_a=malloc((w+1)*sizeof(char));
    

    

    for (int i=0;i<w;i++){
        if(i<sp_in){                //inserisco 'c' all'inizio della stringa
            new_a[i]=c; 
        }

        else if(i<sp_in+lenA){          //fino a che i< ultima posizione stringa 'c' + lunghezza di a[]
            new_a[i]=a[i-sp_in];
        }

        else{                           //altrimenti il resto della stringa viene riempita con 'c'
            new_a[i]=c;
        }
    }

    new_a[w]='\0';

    return new_a;
}


int main(){
    char a[]="ciao";
    int w=8;
    char c='c';

    char *output;
    output=string_center(a,w,c);

    printf("%s",output);
    printf("\n");
}