#include "Header.h"
int main()
{
    int p, n, k, **A;
    printf("Input number of rows\n");
    number(&n);
    choose_type_input(&p);
    A = operation(n, p);
    print_array(n, A);
    printf("Input k:\n");
    number(&k);
    deleting(n, k, A);
    free(A);
    return 0;
}