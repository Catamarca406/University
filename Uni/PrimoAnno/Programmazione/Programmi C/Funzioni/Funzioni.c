#include <stdio.h>

//funzione somma
int somma(int x,int y){
    int somma=x+y;
    return somma;
}

//funzione fattoriale
int fattoriale(int x){
    int fatt=1;
    for(int i=x;i>0;i--){
        fatt=fatt*i;
    }
    return fatt;
}

//funzione pari dispari
int ParDisp(int num){
    if(num%2==0){
        return 1;
    }
    else{
        return 0;
    }
}

//funzione trasforma stringa in capslock
char* Caps(char parola[]){
    for(int i=0; parola[i]!='\0';i++){
        if(parola[i]>96 && parola[i]<123){
            parola[i]=parola[i] -32;
        }
    }
    return parola;
}

//funzione Valore Assoluto
int ValAs(int num){
    if(num >0){
        return num;
    }
    else{
        return -num;
    }
}


int main(){
    int scelta=0;
    printf("Decidi cosa fare:\n (1) Somma \n (2) Fattoriale \n (3) Pari/Dispari \n (4) Trasforma Caps \n (5) Valore assoluto \n");
    scanf("%d",&scelta);
    int risultato;
    switch (scelta)
    {
    case 1:
        //somma di un numero in input
        int num1=0;
        int num2=0;

        printf("Inserisci un numero intero (1):");
        scanf("%d",&num1);
        printf("Inserisci un numero intero (2):");
        scanf("%d",&num2);
        

        risultato = somma(num1,num2);
        printf("%d",risultato);
        break;

    case 2:
        //Fattoriale di un numero in input 
        int input=0;
        
        printf("Inserisci un numero intero per fare il suo fattoriale:");
        scanf("%d",&input);

        risultato=fattoriale(input);
        printf("Il fattoriale di:%d e': %d",input,risultato);
        break;

    case 3:
        //Numero pari/dispari
        int num=0;

        printf("Inserisci un numero:");
        scanf("%d",&num);
        risultato=ParDisp(num);
        if(risultato==1){
            printf("Il numero %d e': pari",num);
        }
        else{
            printf("Il numero %d e': dispari",num);
        }
        break;
    case 4:
        //Conversione stringa in CAPSLock
        char parola[100];
        char* ris;
        printf("Inserisci una stringa:");
        scanf("%s",parola);
        ris=Caps(parola);
        printf("%s e' divetata: %s",parola,ris);

        break;

    case 5:
        //calcolo numero assoluto
        int abs=0;
        printf("Inserisci un numero");
        scanf("%d",&abs);
        risultato = ValAs(abs);
        printf("Il valore assoluto di %d e': %d",abs,risultato);
        break;

    default:
        printf("Ripeti la selezione");
        break;
    }
     
}