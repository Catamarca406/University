#include <stdio.h>
#include <stdbool.h>

int main()
{

    int num=4;
    
    if(num >= 6)
    {
        char condizione[] ="maggiore di 6"; 
        printf("il numero %d è maggiore di 6", num);
        
    }
    else{
        printf("il numero %d è minore di 6",num);
    }

}