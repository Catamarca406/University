#include <stdio.h>
#include <stdlib.h>

typedef struct int_array{
    int dim;
    int *v;
} int_array;

int_array pos_max(float *v, int n){
    
    
    int j=0;
    float max =v[0];
    int ndim=0;
    int lenV=sizeof(v)/sizeof(float);
    
    if(sizeof(v)==sizeof(float) || lenV>1){

    for (int i = 1; i < n; i++){      //cerco il massimo in lista
        if (max <= v[i]){
            max = v[i];
        }
    }

    for(int i=0;i<n;i++){
        if(v[i]==max){
            ndim+=1;
        }
    }

    int_array v1;                   //inizializzo il vettore con le posizioni
    v1.dim=ndim;
    v1.v=malloc(sizeof(int)*ndim);
    

    for(int i=0;i<n;i++){        //stampo le posizioni del vettore
        if(v[i]==max){
            v1.v[j]=i;
            j++;
        }
    }
    return v1;
    }
    if(lenV==1){
        return v;
    }

}

int main(){
    float v[]={3.2, 3.3, 3.2, 1.4, 1.1, 2.0, 3.3};
    int lenV=sizeof(v)/sizeof(float);
    int_array vd =pos_max(v,lenV);

    printf("[");
    for(int i=0;i<vd.dim;i++){
        printf("%d,",vd.v[i]);
    }
    printf("]");
}

//Complessità: Spaziale: O(1), Temporale O(n) 
                






