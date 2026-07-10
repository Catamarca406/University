float* inserisci_media(float* a,int n){ 

    float *b;
    b=malloc(n*sizeof(float));

    int j=0;
    int dist=0;
    int start=0;
    int end=0;

    for(int i=0;i<n+1;i++){
        if(dist<a[i+1]-a[i]){
            dist=a[i+1]-a[i];
            start=i;
            end=i+1;
        }
    }
    
    
    a=realloc(a,n+1);

    int media=0;
    

    for(int i=0;i<n/2;i++){
        if(media<b[i]){
            media=b[i];
            start=i;
            end=i+1;
        }
    }

    int temp=0;
    temp=a[end];
    a[end]=media;
    int new_len=n+1;
    int temp2=0;
    
    for(int i=end+1;i<new_len;i++){
        temp2=a[i];
        a[i]=temp;
    }

    return a;
    

}


int main(){

    int n=5;
    float* a;
    a=malloc(n*(sizeof(float)));\   
    a={9.1,10.8,11.0,12.3,14.5};
    float* result;
    result=inserisci_media(a,n);


    printf("[");
    for(int i=0; i<n;i++){
        printf("%f",a[i]);
    }
    printf("]");
    printf("\n");


    free(a);
    free(result);
}