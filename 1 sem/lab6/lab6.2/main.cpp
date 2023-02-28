#include"hed.h"
int main()
{
    int** A;
    int p, n, m;
    choose_type_input(&p);
    printf("Input number of rows\n");
    number(&n);
    printf("Input number of columns\n");
    number(&m);
    memory(n, m, &A);
    type_input(p, n, m, A);
    print_array(n, m, A);
    sum(n, m, A);
    sort(n, m, A);
    print_array(n, m, A);
    free(A);
    return 0;
}