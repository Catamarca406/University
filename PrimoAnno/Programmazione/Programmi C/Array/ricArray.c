#include <stdio.h>
int main(){
int cerc=0;
printf("Inserisci un valore da cercare nell'Array (tra 10-50):");
scanf("%d",&cerc);

int vet[]={10,20,30.40,50}; 
int lenV=sizeof(vet)/sizeof(vet[0]);
int flag= 0;
int c=0;
while(flag==0 && c<lenV){

   if(cerc== vet[c])
   {
    flag =1;
   }
    c++;
}
if(flag==0){
    printf("Ritenta, sari piu' fortunato!");
}
else{
    printf("Hai indovinato!");
}


}
