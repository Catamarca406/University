#include <stdio.h>
#include <stdlib.h>
//Dato un array di punti restituire una forma che contenga i punti e abbia un perimetro corretto

typedef struct{
    int x;
    int y;
}punto;

typedef struct{
    int perimetro;
    punto* punti;
    int numero_punti;
}forma;

int distanza_manhattan(punto p1, punto p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    
    // Valore assoluto manuale
    if(dx < 0) dx = -dx;
    if(dy < 0) dy = -dy;
    
    return dx + dy;
}



forma crea(punto* punti, int numero_punti){
    forma nuova_forma;
    nuova_forma.punti= malloc(numero_punti*sizeof(punto));

    if(nuova_forma.punti==NULL){
        printf("Errore nell'allocazione della memoria");
        
        nuova_forma.perimetro = 0;
        nuova_forma.numero_punti = 0;
        return nuova_forma;
    }
    
     for(int i = 0; i<numero_punti; i++){
        nuova_forma.punti[i] = punti[i];  // Copia punto per punto
    }

    nuova_forma.perimetro=0;

    for (int i=0; i<numero_punti;i++){
        nuova_forma.perimetro= distanza_manhattan(punti[i],punti[i+1]);
    }

    if(numero_punti > 2) {
        nuova_forma.perimetro += distanza_manhattan(punti[numero_punti-1], punti[0]);
    }

    nuova_forma.numero_punti = numero_punti;
    
    return nuova_forma;
    

}

void stampa_forma(forma f) {
    printf("Forma con %d punti:\n", f.numero_punti);
    for(int i = 0; i < f.numero_punti; i++) {
        printf("  Punto %d: (%d, %d)\n", i, f.punti[i].x, f.punti[i].y);
    }
    printf("Perimetro: %d\n\n", f.perimetro);
}


int main(){

punto punti[]={{10, 24}, {21, 32}, {15, 18}, {8, 25}};
int numero_punti=sizeof(punti)/sizeof(punto);

 printf("Punti originali:\n");
    for(int i = 0; i < numero_punti; i++) {
        printf("Punto %d: (%d, %d)\n", i, punti[i].x, punti[i].y);
    }
    printf("\n");
    
    forma mia_forma = crea(punti, numero_punti);
    
    if(mia_forma.punti != NULL) {
        stampa_forma(mia_forma);
        
        // IMPORTANTE: Libero la memoria allocata
        free(mia_forma.punti);
    }
}