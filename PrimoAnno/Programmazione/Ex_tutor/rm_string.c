#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rimuovi_stringa(char* a,char* b){

    int lenA=strlen(a);
    int lenB=strlen(b);


    int flg=0;
    int j=0;
    int endB=0;

    for(int i=0;i<lenA && j<lenB;i++){   
        if(j<lenB-1){           //controllo fino al penultimo elem
            if((a[i] == b[j]) && (a[i+1]==b[j+1])){     //controllo per coppie
                flg=1;
                j++;
            }
            else{
                flg=0;  
                j=0;
            }
        }
        else{
            if(a[i]==b[j]){             //verifico l'ultimo carattere di b e a
                flg=1;
                j++;    
                endB=i;                 //salvo la posizione della sottostringa in a
            }
            else{
                flg=0;
                j=0;
            }
        }
        
    }

    int startB=(endB-lenB)+1;          //calcolo l'inizio di b

    int k=1;                           // inizializzo per forza ad uno per spostare gli indici

    for(int i=startB;i<lenA;i++){
        a[i]=a[endB+k];                 //sovrascrivo partendo dall'inizio di b e da dopo la fine di b
        k++;
    }
    printf("%s\n",a);
    
    return flg;

}



int main(){

char a[] ="programmazione dei calcolatori";
char b[]="azione";

printf("%d\n",rimuovi_stringa(a,b));

}


//Costo spaziale: O(1)
//Costo temporale:O(n)

