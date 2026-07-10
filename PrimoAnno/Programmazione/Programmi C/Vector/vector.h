typedef struct vector
{
    int cap;   
    int len;   
    int *data; 
} vector;

vector *vector_init();
int vector_append(vector *v, int elem);
int vector_search(vector *v, int elem);
int vector_delete(vector *v, int elem);
int vector_insert(vector *v, int elem, int index);
void vector_print(vector *v);
void vector_free(vector *v);
