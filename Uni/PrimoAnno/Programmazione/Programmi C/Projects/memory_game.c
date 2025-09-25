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


char* init_front(int len) {
    char* front;
    front = malloc((len * len) * sizeof(char));     //alloco memoria per il fronte

    return front;
}

char* fill_front(int len, char* front) {
    srand(time(NULL));                  //rendo le facce delle carte randomiche

    int alf_len = 50;
    char r = rand() % alf_len;
    char alf[] = "abcdefghijklmnopqrstuvwyzABCDEFGHIJKLMNOPQRSTUVWYZ"; //preparo le possibili combinazioni delle carte


    for (int i = 0;i < len * len;i += 2) {
        front[i] = alf[r];          //attribuisco una lettera casuale
        front[i + 1] = front[i];      //faccio lo stesso per la carta successiva, inserendo la stessa, poi scalo di 2 posizioni
        r = rand() % alf_len;    //creo una nuova lettera randomicamente
    }

    int random_pos = rand() % (len * len);
    char temp[1000];
    int c = 0;
    for (int i = 0;i < 1000;i++) {            //rendo casuali le carte sul tavolo
        temp[i] = front[random_pos];
        c = random_pos;
        random_pos = rand() % (len * len);
        front[c] = front[random_pos];
        c = random_pos;
        front[c] = temp[i];
    }

    return front;               //restituisco il nuovo piano di carte
}

void print_front(int len, char* front) {
    for (int i = 0;i < len;i++) {
        printf("%s┃%s", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        for (int j = 0;j < len;j++) {
            printf("[");
            printf("%c", front[i * len + j]);
            printf("]");
        }
        printf("%s┃%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    }
}


void print_guess(int m1, int n1, int m2, int n2, int len, char* front) {
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

    for (int i = 0;i < len;i++) {
        printf("%s┃%s", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        for (int j = 0;j < len;j++) {
            printf("[");
            if ((m1 == i && n1 == j) || (m2 == i && n2 == j)) {
                printf("%c", front[i * len + j]);
            }
            else {
                if (front[i * len + j] == ' ') {
                    printf("%c", ' ');

                }
                else {
                    printf("%s%c%s", ANSI_COLOR_RED, 'X', ANSI_COLOR_RESET);
                }
            }
            printf("]");

        }
        printf("%s┃%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    }

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

void canc_guess(int m1, int n1, int m2, int n2, char* front, int len) {
    front[m1 * len + n1] = ' ';
    front[m2 * len + n2] = ' ';
    
}

int guess(int m1, int n1, int m2, int n2, int len, char* front) {
    if (front[m1 * len + n1] == front[m2 * len + n2]) {
        canc_guess(m1, n1, m2, n2, front, len);
        return 1;
    }
    else
        return -1;
}


int check_victory(int len, char* front) {
   
    for (int i = 0;i < len;i++) {
        for (int j = 0;j < len;j++) {
            if (front[i * len + j] != ' ') {
                return 0;
            }
        }
    }
    return 1;
}


int main() {
    

    int card_rows = 0;
    printf("Insert the number of rows:");
    scanf("%d", &card_rows);

    if (card_rows % 2 != 0) {
        printf("Insert the number of rows (even number):");
        scanf("%d", &card_rows);
    }

    while (card_rows < 2) {
        printf("Error\n");
        printf("Insert the number of rows (>1):");
        scanf("%d", &card_rows);
    }
    char* front = init_front(card_rows); //inizializzo il fronte
    fill_front(card_rows, front);
    //print_front(card_rows, front);
    printf("-----------------------\n");
    int m1 = -1, m2 = -1;
    int n1 = -1, n2 = -1;
    int flag = 0;
    int flag2=0;
    int try = 1;
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



    do {
        print_guess(-1, -1, -1, -1, card_rows, front);
        printf("Chose a card, select m:n (row:col):\n");
        if (scanf("%d.%d", &m1, &n1) != 2) {
            printf("%sSCANF ERROR%s", DARK_RED, ANSI_COLOR_RESET);
            sleep(2);
            continue;;
        }
        system("clear");
        print_guess(m1, n1, -1, -1, card_rows, front);
        do {
            if ((m2 == m1) && (n2 == n1)) {
                printf("You can't cheat :)\n");
            }
            if (scanf("%d.%d", &m2, &n2) != 2) {
                printf("%sSCANF ERROR%s", DARK_RED, ANSI_COLOR_RESET);
                sleep(2);
                continue;;
            }

        } while ((m2 == m1) && (n2 == n1));
        system("clear");
        print_guess(m1, n1, m2, n2, card_rows, front);
        printf("You have %d more tries\n",try);
        flag = guess(m1, n1, m2, n2, card_rows, front);
        if (flag == -1) {
            sleep(2);
            system("clear");
            try--;
        }
        else {
            sleep(2);
            system("clear");
        }
        flag2 = check_victory(card_rows, front);
    } while ((flag2 != 1) && (try>0));
    
    if(try>0){
        printf("%sYOU WIN!%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
    }
    else
        printf("%sYOU LOSE!%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);


}