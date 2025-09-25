#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define DARK_RED           "\x1b[31m" 
#define BLINK              "\x1b[5m"
#define UNBLINK            "\x1b[25m"


// Alloca la memoria per il tabellone di gioco (la "faccia" con le carte)
// Dimensione: len * len (griglia quadrata)
char* init_front(int len) {
    char* front;
    front = malloc((len * len) * sizeof(char));     // alloca memoria
    return front;
}


// Riempie il tabellone con coppie di lettere casuali, poi le mescola
char* fill_front(int len, char* front) {
    srand(time(NULL));                  // seme casuale

    int alf_len = 50;
    char r = rand() % alf_len;
    char alf[] = "abcdefghijklmnopqrstuvwyzABCDEFGHIJKLMNOPQRSTUVWYZ"; // lettere possibili

    // Inserisce coppie di lettere
    for (int i = 0;i < len * len;i += 2) {
        front[i] = alf[r];          // assegna una lettera casuale
        front[i + 1] = front[i];    // copia la stessa lettera (per la coppia)
        r = rand() % alf_len;       // genera una nuova lettera
    }

    // Mescola le carte
    int random_pos = rand() % (len * len);
    char temp[1000];
    int c = 0;
    for (int i = 0;i < 1000;i++) {            
        temp[i] = front[random_pos];
        c = random_pos;
        random_pos = rand() % (len * len);
        front[c] = front[random_pos];
        c = random_pos;
        front[c] = temp[i];
    }

    return front;               // restituisce il tabellone mescolato
}


// Stampa il tabellone intero (debug) mostrando tutte le lettere
void print_front(int len, char* front) {
    for (int i = 0;i < len;i++) {
        printf("%s┃%s", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        for (int j = 0;j < len;j++) {
            printf("[");
            printf("%c", front[i * len + j]);  // mostra la lettera
            printf("]");
        }
        printf("%s┃%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    }
}


// Stampa il tabellone come lo vede il giocatore
// Mostra 'X' per le carte coperte, lettere per le carte scelte e spazi per le carte già eliminate
void print_guess(int m1, int n1, int m2, int n2, int len, char* front) {
    // Bordo superiore
    for (int i = 0;i < len + 1;i++) {
        if (i == 0) {
            printf("%s┏", ANSI_COLOR_GREEN);
        }        
        else
            printf("%s━━━", ANSI_COLOR_GREEN);

        if (i == len) {
            printf("%s┓", ANSI_COLOR_GREEN);
        }
    }
    printf("\n");

    // Contenuto del tabellone
    for (int i = 0;i < len;i++) {
        printf("%s┃%s", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        for (int j = 0;j < len;j++) {
            printf("[");
            if ((m1 == i && n1 == j) || (m2 == i && n2 == j)) {
                // Se la carta è scelta → mostra la lettera
                printf("%c", front[i * len + j]);
            }
            else {
                if (front[i * len + j] == ' ') {
                    // Se la carta è stata eliminata → spazio vuoto
                    printf("%c", ' ');
                }
                else {
                    // Carta coperta → X rossa
                    printf("%s%c%s", ANSI_COLOR_RED, 'X', ANSI_COLOR_RESET);
                }
            }
            printf("]");
        }
        printf("%s┃%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    }

    // Bordo inferiore
    for (int i = 0;i < len + 1;i++) {
        if (i == 0) {
            printf("%s┗", ANSI_COLOR_GREEN);
        }
        else
            printf("%s━━━", ANSI_COLOR_GREEN);

        if (i == len) {
            printf("%s┛", ANSI_COLOR_GREEN);
        }
    }
    printf("\n%s", ANSI_COLOR_RESET);

}


// Elimina due carte indovinate (le sostituisce con spazi vuoti)
void canc_guess(int m1, int n1, int m2, int n2, char* front, int len) {
    front[m1 * len + n1] = ' ';
    front[m2 * len + n2] = ' ';
    
}


// Controlla se due carte scelte sono uguali
// Se sì → le elimina e ritorna 1
// Se no → ritorna -1
int guess(int m1, int n1, int m2, int n2, int len, char* front) {
    if (front[m1 * len + n1] == front[m2 * len + n2]) {
        canc_guess(m1, n1, m2, n2, front, len);
        return 1;
    }
    else
        return -1;
}


// Controlla la condizione di vittoria
// Ritorna 1 se tutte le carte sono state eliminate, altrimenti 0
int check_victory(int len, char* front) {
   
    for (int i = 0;i < len;i++) {
        for (int j = 0;j < len;j++) {
            if (front[i * len + j] != ' ') {
                return 0;  // trovata una carta → non hai ancora vinto
            }
        }
    }
    return 1;  // tutte le carte eliminate → vittoria
}


// Ciclo principale del gioco
// - Chiede la dimensione del tabellone
// - Inizializza e mescola le carte
// - Fa scegliere due carte al giocatore
// - Controlla i tentativi e se la partita è vinta
// - Mostra messaggio finale di vittoria/sconfitta
int main() {
    

    int card_rows = 0;
    printf("Inserisci il numero di righe:");
    scanf("%d", &card_rows);

    // Controlla che sia un numero pari
    if (card_rows % 2 != 0) {
        printf("Inserisci il numero di righe (pari):");
        scanf("%d", &card_rows);
    }

    // Controlla che sia almeno 2
    while (card_rows < 2) {
        printf("Errore\n");
        printf("Inserisci il numero di righe (>1):");
        scanf("%d", &card_rows);
    }

    // Inizializza tabellone
    char* front = init_front(card_rows);
    fill_front(card_rows, front);

    //print_front(card_rows, front);  // debug: mostra lettere
    printf("-----------------------\n");

    // Variabili per le scelte del giocatore
    int m1 = -1, m2 = -1;
    int n1 = -1, n2 = -1;
    int flag = 0;   // verifica se indovinato
    int flag2=0;    // verifica vittoria
    int try = 1;    // numero tentativi disponibili

    // Numero di tentativi in base alla dimensione
    switch (card_rows)
    {
    case 2:
        try=5;
        break;

      case 4:
        try=6;
        break;
    
      case 6:
        try=9;
        break;

      case 8:
        try=12;
        break;
    
    default:
        break;
    }



    // ==== CICLO DI GIOCO PRINCIPALE ====
    do {
        // Stampa tabellone
        print_guess(-1, -1, -1, -1, card_rows, front);

        // Prima carta
        printf("Scegli una carta, formato m:n (riga:colonna):\n");
        if (scanf("%d.%d", &m1, &n1) != 2) {
            printf("%sERRORE SCANF%s", DARK_RED, ANSI_COLOR_RESET);
            sleep(2);
            continue;;
        }
        system("clear");
        print_guess(m1, n1, -1, -1, card_rows, front);

        // Seconda carta (non può essere uguale alla prima)
        do {
            if ((m2 == m1) && (n2 == n1)) {
                printf("Non puoi barare :)\n");
            }
            if (scanf("%d.%d", &m2, &n2) != 2) {
                printf("%sERRORE SCANF%s", DARK_RED, ANSI_COLOR_RESET);
                sleep(2);
                continue;;
            }

        } while ((m2 == m1) && (n2 == n1));

        system("clear");
        // Mostra entrambe le carte scelte
        print_guess(m1, n1, m2, n2, card_rows, front);
        printf("Hai %d tentativi rimasti\n",try);

        // Controlla risultato
        flag = guess(m1, n1, m2, n2, card_rows, front);
        if (flag == -1) {
            // Sbagliato → perdi un tentativo
            sleep(2);
            system("clear");
            try--;
        }
        else {
            // Giusto → carte eliminate
            sleep(2);
            system("clear");
        }

        // Controlla vittoria
        flag2 = check_victory(card_rows, front);
    } while ((flag2 != 1) && (try>0));
    
    // ==== MESSAGGIO FINALE ====
    if(try>0){
        printf("%sHAI VINTO!%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
    }
    else
        printf("%sHAI PERSO!%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);


}
