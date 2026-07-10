#include <stdio.h>
// riordinare un vettore 

int vSort(int *v,int lenV,int temp){
    
    for(int j=0;j<lenV-1;j++){
        for(int i=0;i<lenV-1;i++){
            if(v[i]>v[i+1]){
                temp=v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
            }
        }
    }
    return *v;
}

int stamp(int *v,int lenV){
    printf("[");
    for(int i=0;i<lenV;i++){
        printf("%d,",v[i]);
    }
    printf("]\n");
}


int main(){
    int v[]={10,4,5,3,-6,17};
    int lenV=sizeof(v)/sizeof(int);
    int temp=0;
    
    vSort(v,lenV,temp);
    stamp(v,lenV);
}



//Costo: T(n) = O(n^2)



    
