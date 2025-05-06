#include <stdio.h>

/*struct Persona
{
    char nome[20];
    char cognome[20];
    int eta;
};

/*
int main(){
    //Ex1 definizione di una prima struct di tipo persona 
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
//Ex2 calcolo dell'età media di un gruppo di persone
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

/*
//Ex4 Definizione di una struttura libro e stampa dei dati 
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
    scanf("%lf",&libro.prezzo);

    printf("Il libro: %s,con codice: %s costa: %.2f euro ",libro.nome,libro.isbm,libro.prezzo); //con .2f ho troncato i valori del prezzo
}*/

//Ex5 calcolo del totale di una fattura con più elementi usando una struttura "Prodotto"
/*struct Prodotto
{
    char nome[20];
    char barCode[30];
    double prezzo[200];
};
int fattura(double *prezzo,int sc){
    double somma=0;
    for(int i=0;i<sc;i++){
        somma+=prezzo[i];
    }
return somma;
}

int main(){
    struct Prodotto prodotto;
    int sc=0;

    printf("Quanti prodotti vuoi inserire?");
    scanf("%d",&sc);

    for(int i=0; i<sc;i++){
        printf("Inserisci il nome del prodotto:");
        scanf("%s",prodotto.nome[i]);
        printf("Inserisci il codice a barre:");
        scanf("%s",prodotto.barCode[i]);
        printf("Inserisci il prezzo:");
        scanf("%lf",&prodotto.prezzo[i]);
    }
    
    double fax=fattura(prodotto.prezzo,sc);

    printf("La fattura ammonta a:%lf",fax);
}*/

//Ex6 definizione di una struttura Studente con voto e calcolo della media
struct Studente
{
    char nome[20];
    char cognome[20];
    char classe[20];
    float voto[];
};
float mediaVoti(float *voto[],int sc){
    float somma=0;
    for(int i=0;i<sc;i++){
        somma+=*voto[i];
    }
    int media=somma/sc;
    return media;
}
int main(){
    struct Studente studente;
    int sc=0;

    printf("Inserisci il nome dello studente: ");
    scanf("%s",studente.nome);
    printf("Inserisci il cognome dello studente: ");
    scanf("%s",studente.cognome);
    printf("Quanti voti devi registrare? ");
    scanf("%d",&sc);

    for(int i=0;i<sc;i++){
        printf("Inserisci il voto:");
        scanf("%f",&studente.voto[i]);
    }

    float media=0;
    media=mediaVoti(studente.voto,sc);
    printf("La media dello studente: %s %s e': %f",studente.nome,studente.cognome,studente.voto);
    
    
}


