#include "hed.h"
int main()
{
    int *A, n;
    printf("Input number of elements\n");
    num_element(&n);
    memory(&A,  n);
    scan_array(n, A);
    print_array(n, A);
    overexposure(&A, n);
    count(A, n);
    printf("New ");
    print_array(2*n, A);
    free(A);
    return 0;
}
