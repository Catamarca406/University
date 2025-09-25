#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* mix_ball (int cupLen){

srand(time(NULL));

int r = rand() %cupLen;


int *cup=calloc(cupLen,sizeof(int));
cup[r]=1;
return cup;
}

int print_cup(int *cup,int cupLen){
    printf("[");
    for(int i=0;i<cupLen-1;i++){
        printf("%d,",cup[i]);
    }
    printf("%d]\n",cup[cupLen-1]);
}

char get_diff_let(int cupLen, char *cup){
  char r2= rand() %26 + 65; 

    for(int i=0;i<cupLen;i++){
        if(cup[i]==r2){
          return get_diff_let(cupLen,cup);
        }
    }
    return r2;
}

char print_cup2_0(char *cup,int cupLen){
    for(int i=0;i<cupLen;i++){
       cup[i]=get_diff_let(cupLen,cup);
    }

    printf("[");
    for(int i=0;i<cupLen-1;i++){
       
        printf("%c,",cup[i]);
    }
    printf("%c]\n",cup[cupLen-1]);
}


void guess_value(char guess, char *cup2,int cupLen,int *cup){
   for(int i=0;i<cupLen;i++){
    if(cup2[i]==guess){
        if(cup[i]==1){
            printf("True, you win!\n");
            break;
        }
        else
            printf("False, try again :(\n");
    }
   }
}


int main(){
int num_cup=0;
printf("How many cups do you want?");
scanf("%d",&num_cup);

int *cup = mix_ball(num_cup);

char *cup2=malloc(num_cup*sizeof(char));
print_cup2_0(cup2,num_cup);

char guess;
printf("Insert your guess!\n");
scanf(" %c",&guess);
guess_value(guess,cup2,num_cup,cup);
print_cup(cup,num_cup);

}