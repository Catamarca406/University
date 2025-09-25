#include <stdio.h>

void sort_by_vocals(char *a){
int lenA=0;
    
    while(a[lenA]!='\0'){
        lenA++;
    }
    int j=0;
    char temp[lenA];

    for(int i=0;i<lenA;i++){

        if(a[i]>= 65 && a[i]<=90){          //verifico se la lettera è maiuscola
            switch (a[i])
            {
            case 65:                //verfico se è A
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;
            
            case 69:                //verfico se è E
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;

            case 73:                //verfico se è I
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;

            case 79:                //verfico se è O
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;

            case 85:                //verfico se è U
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;
            }
        }

        if(a[i]>= 97 &&  a[i]<=122){
            switch (a[i])
            {
            case 97:                //verfico se è A
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;
            
            case 101:                //verfico se è E
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;

            case 105:                //verfico se è I
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;

            case 111:                //verfico se è O
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;

            case 117:                //verfico se è U
                if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1]
                a[i+1]=temp;
                }
                break;
            }
        }
            
    }


}


int main(){
char a[]=".pr0grAmMaz1onE-C*"

}