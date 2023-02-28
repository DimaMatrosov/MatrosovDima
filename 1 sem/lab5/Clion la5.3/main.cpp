#include "Functions.h"
int main()
{
    int** A, * B;
    int p, n, m;
    choose_type_input(&p);
    printf("Input number of rows\n");
    number(&n);
    printf("Input number of columns\n");
    number(&m);
    A = memory(n, m);
    type_input(p, n, m, A);
    print_array(n, m, A);
    neg_col(m, n, A);
    free(A);
    return 0;
}
