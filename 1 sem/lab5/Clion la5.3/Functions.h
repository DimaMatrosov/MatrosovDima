#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void choose_type_input(int* p);
void print_array(int n, int m, int** A);
void scan_array_rand(int n, int m, int** A);
void print_new_array(int n, int m, int h, int* B, int** A);
void scan_array(int n, int m, int** A);
void number(int* k);
void type_input(int p, int n, int m, int** A);

void neg_col(int m, int n, int** A);

int** memory(int n, int m);
void overexposure(int **A,int n, int b);