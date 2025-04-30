#include <stdio.h>

/*struct Persona
{
    char nome[20];
    char cognome[20];
    int eta;
};

/*
int main(){
    //definizione di una prima struct di tipo persona 
    struct Persona persona;   //richiamo la struct nel main 

    printf("Inserisci il nome:");
    scanf("%s",persona.nome);
    printf("Inserisci il cognome:");
    scanf("%s",persona.cognome);
    printf("Inserisci l'eta:");
    scanf("%d",&persona.eta);     

    printf("I dati della persona sono:\n");
    printf("Nome: %s\n",persona.nome);
    printf("Cognnome: %s\n",persona.cognome);
    printf("Eta: %d\n",persona.eta);
    return 0;
}*/




/*
int main(){
//calcolo dell'età media di un gruppo di persone
    struct Persona persona[5];   //Per inserire più valori dentro una struct persona bisogna costruire un vettore

    for(int i=0;i<5;i++){
        printf("Nome:");
        scanf("%s",persona[i].nome);
        printf("Cognome:");
        scanf("%s",persona[i].cognome);
        printf("Eta:");
        scanf("%d",&persona[i].eta);
    }

    int sommaEta=0;
    for(int i=0;i<5;i++){
        sommaEta+=persona[i].eta;
    }
    int etaMedia=0;
    etaMedia=sommaEta/5;

    printf("La media delle eta e':%d",etaMedia);

}*/

//Definizione di una struttura libro e stampa dei dati 
struct Libro
{
  char nome[50];
  char isbm[20];
  double prezzo;
};

int main(){
    struct Libro libro;

    printf("Inserisci il nome: ");
    scanf("%s",libro.nome);
    printf("Inserisci l'isbm: ");
    scanf("%s",libro.isbm);
    printf("Inserisci il prezzo: ");
    scanf("%f",&libro.prezzo);

    printf("Il libro: %s, con codice: %s costa: %d euro ",libro.nome,libro.isbm,libro.prezzo);


    
    

    
    
}