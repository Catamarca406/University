#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rimuovi_stringa(char *a, char *b){
    
    int lenA=strlen(a);
    int lenB=strlen(b);

    if(lenB > lenA){
        return 0;
    }

    int j=0;
    int check=0;
    int end=0;

    for(int i=0;i<lenA;i++){
        if(a[i]==b[j] && j<lenB){
            check=1;
            j++;
            end=i;      //salvo la posizione dell'ultimo carattere della sottostringa
        }
        else if(a[i]!=b[j] && j<lenB){
            check=0;
            j=0;
        }
    }
    
    int start=(end-lenB)+1; //ricavo l'inizio della sottostringa tramite (fine-len)+1 perché inizio da pos 0
    

    if(check==1){           //Se la sottostringa è presente shifto la stringa
        j=end+1;
        for(int i=start;i<lenA;i++){
           a[i]=a[j];           //comincio dall'inizio della sottostringa 
           j++;
        }
    }
    else{
        return 0;
    }

    printf("%s\n",a);

    return check;

}

int main(){
    char a[]="programmazione dei calcolatori";
    char b[] = "azione";
    int result=rimuovi_stringa(a,b);
    printf("%d\n",result);
    
}


//Costo spaziale: O(1)
//Costo temporale: O(n)