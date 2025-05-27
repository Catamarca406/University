#include <stdio.h>
#include <string.h>

void filtra(char *a, int *b) {
     // Calcolo la lunghezza della stringa
    int j = 0;         // Indice per la nuova stringa

    // Itero sui caratteri della stringa
    for (int i = 0; i < strlen(a); i++) {
        if (b[i] == 1) {
            a[j++] = a[i]; // Sposto il carattere nella nuova posizione
            printf("\n",j);

        }
    }
    a[j] = '\0'; // Aggiungo il terminatore di stringa IMPORTANTE aggiungiamo il terminatore \0 a j, che "taglia" tutto ciò che rimane nella stringa dopo j
}

int main() {
    char a[] = "algoritmo";             // Stringa di input
    int b[] = {0, 0, 0, 1, 0, 0, 1, 0, 1}; // Array binario

    filtra(a, b); // Chiamo la funzione

    printf("%s\n", a); // Stampo il risultato
    return 0;
}

