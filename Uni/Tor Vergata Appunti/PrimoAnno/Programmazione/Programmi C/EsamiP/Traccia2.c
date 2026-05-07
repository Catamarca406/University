#include <stdio.h>
#include <string.h>

//creare una funzione che prese due stringhe deve concatenare b ad a, modificando a
char *str_cat(char *a, int n, char *b){     /*prende due stringhe, n è la dimensione dell'array 
                                             che contiene a*/
    int j=0;
    int k=0;
    int i;
    int lenA=0;
    int lenB=0;

    while(a[j]!= '\0'){
        lenA++;
        j++;
    }
    int dif=n-1;

    while(b[k]!='\0'){
        lenB++;
        k++;
    }

    for(i=0;i<dif-1;i++){
        a[lenA]=b[i]; 
        lenA++;
    }
    a[dif]='\0';
    
    while(i<=n && j<=lenB){
        a[i]=b[j];
        i++;
        j++;
    }
        return a;
    
    
}

int main(){
    char a[5]="buon";
    char b[]="giorno";
    int lenA=sizeof(a)/sizeof(char);   //restituisce la lunghezza della stringa + '\0'
    int lenB=sizeof(b)/sizeof(char);
    
    printf("%s\n",str_cat(a,10,b));
    
}