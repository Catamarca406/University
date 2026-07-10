#include <stdio.h>

int main(){

    int ripetizione;
   
    printf("Quante volte vuoi ripetere il programma?:");
    scanf("%d", &ripetizione);
    
    
    for(int c=0; c<ripetizione; c++) {    
        int mesiAnno;
        printf("Inserisci un numero:\n");
        scanf("%d",&mesiAnno);
        

        switch (mesiAnno)
        {
            case 1:
                printf("Gennaio\n");
                break;

            case 2:
                printf("Febbraio\n");
                break;

            case 3:
                printf("Marzo\n");
                break;

            case 4:
                printf("Aprile\n");
                break;

            case 5:
                printf("Maggio\n");
                break;
            
            case 6:
                printf("Giugno\n");
                break;
            
            case 7:
                printf("Luglio\n");
                break;

            case 8:
                printf("Agosto\n");
                break;

            case 9:
                printf("Settembre\n");
                break;

            case 10:
                printf("Ottobre\n");
                break;

            case 11:
                printf("Novembre\n");
                break;

            case 12:
                printf("Dicembre\n");
                break;

            default:
                if(mesiAnno<=0)
                 {
                    printf("Non esistono mesi minori/uguali di 0\n");
                 }
                else{
                    printf("Non ci sono piu' di 12 mesi\n");
                 }
                
                break;

        }
    }
        



}