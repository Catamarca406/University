#include <stdio.h>
int main(){
    //puntaNO
    /*int x=50;
    int *ptrx=&x;
    printf("%p",ptrx);
    */

    int a[]={12,3,8};
    int *b = a;
    printf("%p %p\n",b, a);
    printf("%d", *(a + 1));
    // a[1] <-> *(a + 1)

}

// 