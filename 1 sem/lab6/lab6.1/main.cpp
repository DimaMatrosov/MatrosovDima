#include "hed.h"
int main()
{
    int *A, n, p;

    printf("Input number of elements\n");
    num_element(&n);
    memory(&A, n);
    choose_type_input(&p);
    scan_array(n, p, A);
    print_array(n, p, A);
    sort1(A, n);//выбор
    sort2(A, n);//пузырек
    sort3(A, n);//обратный
    print_array(n, p, A);
    free(A);
    return 0;
}
