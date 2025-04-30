#include <stdio.h>
#include <stdlib.h>
int main(){
    //inserimento di valori in input dentro un array
    
    int n=0;
    int c=0;
    int ripeti=0;
    int *a;

    printf("Quante valori interi vuoi nel vettore?");
    scanf("%d",&ripeti);
  
    a=malloc(ripeti*(sizeof(int)));
    int *vet;
    vet=a;

    for (int i=0; i<ripeti;i++)
    {
        printf("Inserisci un numero intero:");
        scanf("%d",&n);
        vet[i]=n;
        
    }
    
    printf("Il vettore vale:\n");
    for(int i=0;i<ripeti;i++){
      printf("%d ",vet[i]);
    }
    free(a);
}