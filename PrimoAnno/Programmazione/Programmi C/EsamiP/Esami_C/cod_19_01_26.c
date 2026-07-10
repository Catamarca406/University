#include <stdio.h>
#include <stdlib.h>

int *pos_dei_minori(int *a, int n, int k, int *m){

    int count_min = 0;
    //Conto gli elementi minori di k
    for(int i=0;i<n;i++){
        if(a[i] < k){
            count_min++;
        }
    }
    // Scrivo nella posizione di memoria la dim del nuovo array
    *m = count_min;

    //Alloco l'array ausiliario per restituire gli indici
    int* arr_pos;
    arr_pos = malloc(count_min*sizeof(int));

    //creo un contatore per spostarmi sul secondo array
    int j = 0;

    for(int i=0;i<n;i++){
        if(a[i] < k){
            arr_pos[j] = i;
            j++;
        }
    }

    return arr_pos;


    //Complessità Spaziale: O(1) perché viene creato un solo array per l'output
    //Complessità Temporale: O(n), scorro l'array solo due volte, una per controllare: valori < k e una per inserire gli indici

}



int main() {
    int a[] = {10,150,22,30,5,200};// definizione di a;
    int n = sizeof(a)/sizeof(int);
    int m;
    int *b = pos_dei_minori(a, n, 100, &m);
    for(int i = 0; i < m; i++){
    printf("%d\n", b[i]);
    }
}
