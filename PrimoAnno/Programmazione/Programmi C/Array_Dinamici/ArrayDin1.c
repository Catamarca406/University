#include <stdio.h>
#include "../Vector/vector.h"

int main(){

    vector *v=vector_init();
    vector_append(v,10);
    vector_print(v);

    return 0;
}


