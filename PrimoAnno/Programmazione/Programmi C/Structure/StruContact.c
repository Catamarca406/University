#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact{   
    char *nome;
    char telefono[11];
    int eta;
}contact;
   
int len(char *stringa){
    int i=0;
    while(stringa[i]!= '\0'){
        i++;
    }
    return i;
}

contact crea_contact(char *nome,char *telefono,int eta){
    
   contact c;
   int lenN=len(nome);  //richiamo le lunghezze delle due stringhe
   int lenT=len(telefono);  

   c.nome=malloc(sizeof(lenN+1)*sizeof(char));    //alloco spazio per il nome, char dinamico
   

   if(c.nome != NULL){      //copio valore per valore nella stringa
    for(int i=0;i<=lenN;i++){
        c.nome[i]=nome[i];
        if(nome[i] == '\0')
            break;
    }
   }

   for(int i=0;i<lenT && i<10;i++){  //copio valore per valore nella stringa
    c.telefono[i]=telefono[i];
   }
   c.telefono[10]='\0';
   c.eta=eta;
   return c;                //returno la struct 
}

void stamp_contact(contact c){          //riprendo la struct e ne stampo i valori    
    printf("Nome: %s\n",c.nome);
    printf("Telefono: %s\n",c.telefono);
    printf("Eta: %d\n",c.eta);
}

int main(){
    contact cont1=crea_contact("Mario","3475439843",19);
    contact cont2=crea_contact("Giulio","3423555395",16);
    
    
    stamp_contact(cont1);
    stamp_contact(cont2);


    free(cont1.nome);
    free(cont2.nome);

}