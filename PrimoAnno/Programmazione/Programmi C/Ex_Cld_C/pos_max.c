#include <stdio.h>
#include <stdlib.h>


typedef struct int_array {
int dim;
int *v;
}
int_array;


int_array pos_max (float *a, int n){
    
    int_array b;

    b.v=malloc(n*sizeof(int));
    b.dim=n;

    float find_max=a[0];

    for(int i=1;i<n;i++){           //cerco il massimo nell'array 
        if(find_max<=a[i]){
            find_max=a[i];
        }
    }
    
    int j=0;
    int count_max=0;

    for(int i=0;i<n;i++){           
        if(find_max==a[i]){
            count_max++;
        }
    }
    
    b.dim=count_max;        //realloco la memoria

    for(int i=0;i<n;i++){           //ricerco la posizione del max e delle sue copie
        if(find_max==a[i]){
            b.v[j]=i;
            j++;
        }
    }

    return b;

}

int main(){

    float a[]={20.4,10.2,3.1,4.0,6.1,20.4};
    int n=sizeof(a)/sizeof(float);
    
    
    int_array result = pos_max(a,n);
    printf("%d\n", result.dim);
    for(int i=0; i<result.dim;i++){
        printf("%d - ", result.v[i]);
    }
    
    

}

