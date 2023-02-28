#include "ff.h"

char* categories[5] =
        {         "drama",
                 "adventures",
                "detective",
                 "comedy",
                "action",
        };
int str_len(char *str)
{
    int len = 0;
    while (*(str + len) != '\0')
        len++;
    return len;
}

void get_str(char **string)
{
    int len=0;
    *string = (char*) malloc(sizeof(char));
    char c;
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        *(*string + i) = c;
        i++;
        len++;
        *string = (char *) realloc(*string, len);
    }
    *(*string + i) = '\0';
}

void num_element(int* k)
{
    while(scanf_s("%d", k) != 1 || *k <= 0 || getchar() != '\n') {
        printf("Wrong input. Try again:");
        rewind(stdin);
    }
}

void qsort_episodes(manga* anime, int left, int right) {
    int i = left, j = right;
    manga gap = anime[(left + right) / 2];
    do {
        while (anime[i].episode < gap.episode)
            i++;
        while (anime[j].episode > gap.episode)
            j--;
        if (i <= j) {
            manga temp = anime[i];
            anime[i] = anime[j];
            anime[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (i < right)
        qsort_episodes(anime, i, right);
    if (j > left)
        qsort_episodes(anime, left, j);
}

void sort_year(int k,manga* anime) {
    for (int i = 0; i < k - 1; i++) {
        int i1 = i;
        for (int j = i + 1; j < k; j++)
            if (anime[i1].year > anime[j].year) i1 = j;
        manga m = anime[i];
        anime[i] = anime[i1];
        anime[i1] = m;
    }
    printing(k, anime);
}

void printing(int n, manga *anime)
{
    for (int i = 0; i < n; i++)
        printf("%10s  num of episodes:%d  year of release:%d  category:%s\n", anime[i].name, anime[i].episode, anime[i].year, categories[anime[i].category]);
}

void input(int *var, char *str)
{
    printf("%s", str);
    while (!scanf_s("%d", var) || *var > 6 || *var < 0 || getchar() != '\n')
    {
        printf("Wrong input! Input again:");
        rewind(stdin);
    }
}

void input_filds(int *var, char *str)
{
    printf("%s", str);
    while (!scanf_s("%d", var) || *var > 4 || *var < 1 || getchar() != '\n')
    {
        printf("Wrong input! Input again:");
        rewind(stdin);
    }
}

void sort_2_filds(int k,manga* anime) {
    first_field( k, anime);
    second_field( k, anime);
}

void first_field(int k, manga* anime){
    printf("\nFirst field: 1.Num of episodes sort  2.year sort  3.name sort 4. category sort\n");
    int task;
    input_filds(&task, "Input task:");
    if (task == 1) {
        qsort_episodes(anime, 0, k - 1);
        printing(k, anime);
    }
    if (task == 2) {
        sort_year(k, anime);
    }
    if (task == 3) {
        insertsort_name(anime,k);
        printing(k, anime);
    }
    if (task == 4) {
        insertsort_ctg(anime, k);
        printing(k, anime);
    }
}

void second_field(int k, manga* anime){
    printf("\nSecond field:  1.Num of episodes sort  2.year sort  3.name sort 4.category sort\n");
    int task;
    input_filds(&task, "Input task:");
    if (task == 1) {
        sort_episodes( k, anime);
        printing(k, anime);
    }
    if (task == 2) {
        sort_year2( k, anime);
        printing(k, anime);
    }
    if (task == 3) {
        insertsort_name2(anime,k);
        printing(k, anime);
    }
    if (task == 4) {
        insertsort_ctg2(anime, k);
        printing(k, anime);
    }
}

void sort_episodes(int k,manga* anime) {
    for (int i = 0; i < k - 1; i++) {
        int i1 = i;
        for (int j = i + 1; j < k; j++)
            if ((anime[i1].year == anime[j].year || anime[i1].name == anime[j].name) && anime[i1].episode > anime[j].episode)
                i1 = j;
        manga m = anime[i];
        anime[i] = anime[i1];
        anime[i1] = m;
    }
}

void sort_year2(int k,manga* anime) {
    for (int i = 0; i < k - 1; i++) {
        int i1 = i;
        for (int j = i + 1; j < k; j++)
            if ((anime[i1].episode == anime[j].episode || anime[i1].name == anime[j].name) && anime[i1].year > anime[j].year)
                i1 = j;
        manga m = anime[i];
        anime[i] = anime[i1];
        anime[i1] = m;
    }
}

void inputing_anime(manga* anime,int n){
    int serias,year;
    char *name, *cat;
    for (int i = 0; i < n; i++) {
        printf("input name of anime");
        get_str( &name);
        printf("input number of episodes");
        num_element( &serias);
        printf("input year of realise");
        num_element( &year);
        printf("input category(drama/adventures/detective/comedy/action)\n");
        get_str( &cat);
        category_test(cat);
        anime[i].name = calloc(str_len(name), sizeof(char));
        anime[i].name = name;
        anime[i].episode = serias;
        anime[i].year = year;
        category(cat, anime, i);
        if(i != n-1)
            printf(" next anime\n");
    }
}

void menu(manga *anime, int n){
    while (1){
        printf("\nTasks: 1. Num of episodes sort 2. year sort 3. name sort 4. sort by two fields 5.delete struct 6.category sort 0.Stop\n");
        int task, del;
        input(&task, "Input task:");
        if (!task) {
            break;
        }
        if (task == 1) {
            qsort_episodes(anime, 0, n - 1);
            printing(n, anime);
        }
        if (task == 2) {
            sort_year(n, anime);
        }
        if (task == 3) {
            insertsort_name( anime, n);
            printing(n, anime);
        }
        if (task == 4) {
            sort_2_filds(n, anime);
        }
        if (task == 5) {
            printf("input num to delete");
            num_element(&del);
            delete_struct(&anime, &n, del);
            printing(n, anime);
        }
        if (task == 6) {
            insertsort_ctg( anime, n);
            printing(n, anime);
        }
    }
}

void free_memory(manga* anime, int n) {
    for (int i = 0; i < n; ++i) {
        free(anime[i].name);
    }
    free(anime);
}

void insertsort_name(manga* anime, int n){
    for(int i=0;i<n; i++){
       int j=i-1;
       while(j>=0 &&(strcmp(anime[j].name, anime[j+1].name)>0)){
           manga temp = anime[j];
           anime[j] = anime[j+1];
           anime[j+1]=temp;
           j--;
       }
    }
}

void insertsort_ctg(manga* anime, int n){
    for(int i=0;i<n; i++){
        int j=i-1;
        while(j>=0 &&(strcmp(categories[anime[j].category],categories[anime[j+1].category])>0)){
            manga temp = anime[j];
            anime[j] = anime[j+1];
            anime[j+1]=temp;
            j--;
        }
    }
}

void insertsort_ctg2(manga* anime, int n){
    for(int i=0;i<n; i++){
        int j=i-1;
        if(anime[i].episode == anime[j].episode || anime[i].year == anime[j].year || anime[i].name== anime[j].name)
        while(j>=0 &&(strcmp(categories[anime[j].category],categories[anime[j+1].category])>0)){
            manga temp = anime[j];
            anime[j] = anime[j+1];
            anime[j+1]=temp;
            j--;
        }
    }
}

void insertsort_name2(manga* anime, int n){
    for(int i=0;i<n; i++){
        int j=i-1;
        if(anime[i].episode == anime[j].episode || anime[i].year == anime[j].year)
            while(j>=0 &&(strcmp(anime[j].name, anime[j+1].name)>0)){
            manga temp = anime[j];
            anime[j] = anime[j+1];
            anime[j+1]=temp;
            j--;
        }
    }
}

void delete_struct(manga** anime, int* n, int del){
    int ind = del - 1;
    free(anime[ind]->name);
    for (int i = ind; i < *n - 1; i++)
    {
        (*anime)[i] = (*anime)[i + 1];
    }
    *n = *n -1;
   *anime = (manga*)realloc(*anime, *n * sizeof(manga));
}

void category(char* cat, manga* anime, int i){
if (strcmp (cat, "drama")==0)
    anime[i].category=drama;
if (strcmp (cat, "adventures")==0)
    anime[i].category=adventures;
if (strcmp (cat, "detective")==0)
    anime[i].category=detective;
if (strcmp (cat, "comedy")==0)
    anime[i].category=comedy;
if (strcmp (cat, "action")==0)
    anime[i].category=action;
}

void category_test(char* cat){
    if (strcmp (cat, "drama")!=0 && strcmp (cat, "adventures")!=0 && strcmp (cat, "detective")!=0 && strcmp (cat, "comedy")!=0 && strcmp (cat, "action")!=0){
        printf("Wrong input. Restart the program");
        exit(0);
    }
}


