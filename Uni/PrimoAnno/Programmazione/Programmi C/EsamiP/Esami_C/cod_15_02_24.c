#include <stdio.h>
#include <stdlib.h>

int get_len(char *a){
int lenA = 0;
    while (a[lenA] != '\0')
    {
        lenA++;
    }
    return lenA;
}

char *get_format(char *a)
{
    int lenA=0;
    lenA=get_len(a);
    int j=0;


    for(int i=0;i<lenA;i++){        //trasformo la stringa con le unità dei num precedenti e il car. ';'
        if(a[i]==';'){
            a[j]=a[i-1];
            a[j+1]=a[i];
            j+=2;
        }
        else if(a[i]=='\0'){
            a[j]=a[i-1];
            j++;
        }
    }
    a[j]='\0';
    return a;


    for(int i=0;i<j;i++){
        if(a[i]!=';'){
            if((a[i]-'0')%2==0){
                a[i]='p';
            }
            else
                a[i]='d';
        }
        else if(a[i]=='\0'){
            if((a[i]-'0')%2==0){
                a[i]='p';
            }
            else 
                a[i]='d';
        }
    }

}

int main()
{

    char a[] = "7;90;0;123;8;4";
    printf("%s",a);
    printf("\n");
    get_format(a);
    for(int i=0;i<15;i++){
        printf("%c",a[i]);
    }
    printf("\n");

}