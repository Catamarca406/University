#include <stdio.h>
#include <stdlib.h>
typedef struct vector{
    int *val;
    int cap;
    int dim;
    
}vector;

vector v_init(){
    vector v={NULL,0,0};
    return v;
}

vector append(vector v,int elem){
    if(v.dim==v.cap){           //se la dimensione è pari alla capacità devo cap
        v.cap=2*(v.cap+1);      //aumento di almeno 2 volte la capacità per cap +1, cap potrebbe essere = 0
        v.val=realloc(v.val,v.cap*sizeof(int)); //realloco dando lista e la nuova capacità 
    }
    v.val[v.dim]=elem;      //aggiungo l'elemento richiesto in ultima posizione
    v.dim++;            //aumento la lista di uno
    return v;   
}

vector pop(vector v){
    if(v.dim>0){            //se la dimensione è > 0
        v.dim--;         //decremento la dimensione del vettore
    
    if(v.dim<v.cap/4){      
        v.cap=v.cap/2;
        v.val=realloc(v.val,(v.cap)*sizeof(int));
    }
    }
    return v;
}

vector cas_insert(vector v,int elem,int pos){
    int temp=0;
    int a;
    if(v.dim==v.cap){
        v.cap=2*(v.cap+1);
        v.val=realloc(v.val,v.cap*sizeof(int));
    }
    //v.dim++;
    temp = v.val[pos];
    for(int i=pos;i<v.dim;i++){
        a = v.val[i+1];
        v.val[i+1]=temp;
        temp = a;
    }
    v.val[pos] = elem;
    return v;
}

void stampa(vector v){  
    printf("[");
    for(int i=0;i<v.dim;i++){
        printf("%d",v.val[i]);
        if(i<v.dim-1)
            printf(",");
    }
    printf("]\n");
}

int main(){
    vector v;
    v=v_init();     //inizializzo il vettore
    int scelta=8;
    int n=0;
    
    printf("Inserisci un numero per appendare:\n");
    for(int i=0;i<scelta;i++){          //inserisco i valori nel vettore, con append
        scanf("%d",&n);
        v = append(v,n);
    }

    v = cas_insert(v,29,2);             //provo ad inserire in posizione 2, 29
    stampa(v);                      //stampo il vettore

}