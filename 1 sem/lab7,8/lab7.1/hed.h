#include <stdlib.h>
#include <stdio.h>
int count_substrings(char *string, char *substring);
void input(int *var,  char *str);
void task1(int cnt);
void task2(int cnt);
void run_task(int (*func)(int), int cnt);
void getstr(char **string, int len);
