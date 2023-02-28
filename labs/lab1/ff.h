#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef enum {
    drama = 0, adventures, detective, comedy, action
}ctg;
typedef struct
{
    ctg category;
    int year;
    char *name;
    int episode;
}manga;

int str_len(char *str);
void qsort_episodes(manga* anime, int left, int right);
void sort_2_filds(int k,manga* anime);
void sort_year(int k,manga* anime);
void printing(int argc, manga *list);
void input(int *var, char *str);
void input_filds(int *var, char *str);
void sort_episodes(int k,manga* anime);
void sort_year2(int k,manga* anime);
void get_str(char **string);
void num_element(int* k);
void second_field(int k, manga* anime);
void first_field(int k, manga* anime);
void inputing_anime(manga* anime,int n);
void menu(manga *anime, int n);
void free_memory(manga* anime, int n);
void insertsort_name2(manga* anime, int n);
void insertsort_name(manga* anime, int n);
void category_test(char* cat);
void delete_struct(manga** anime, int *n, int del);
void category(char* cat, manga* anime, int i);
void insertsort_ctg(manga* anime, int n);
void insertsort_ctg2(manga* anime, int n);