#include <stdio.h>
#include <stdlib.h>

char *string_center(char *a, int w, char c){
    int lenA=0;

    while(a[lenA]!='\0'){
        lenA++;
    }

    if(lenA>=w){
        char* new_a;
        new_a=malloc((lenA+1)*sizeof(char));
        for(int i=0;i<lenA;i++){
            new_a[i]=a[i];
        }
        new_a[lenA]='\0';

        return new_a;
    }

    char *w_center;
    w_center=malloc((w+1)*sizeof(char));

    int c_space=w-lenA;

    if((w-lenA) %2==0){

        int Lspace=c_space/2;           //Calcolo spazio sinistro
        int Rspace=Lspace+lenA;         //Calcolo spazio destro= Spazio sinistro + a
        int j=0;

        for(int i=0;i<w;i++){
            if(i<(Lspace)){
                w_center[i]=c;
            }
            if(i>=Lspace && i<Rspace){
                w_center[i]=a[j];
                j++;
            }
            if(i>=Rspace){
                w_center[i]=c;
            }
        
        }
        w_center[w]='\0';

    }
    else{
        int Lspace=c_space/2;           
        int Rspace=Lspace+lenA;        
        int j=0;

        for(int i=0;i<w;i++){
            if(i<(Lspace)){
                w_center[i]=c;
            }
            if(i>=Lspace && i<Rspace){
                w_center[i]=a[j];
                j++;
            }
            if(i>=Rspace){
                w_center[i]=c;
            }
            
            }
        w_center[w]='\0';

        }
    return w_center;
    }



int main(){

    printf("%s\n",string_center("hello", 11, '*'));  // "***hello***"
    
}

//Costo spaziale: O(n)
//Costo temporale: O(n)