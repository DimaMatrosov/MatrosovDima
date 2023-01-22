#include "hed.h"
void task1(int cnt)
{
    printf("Num: %d", cnt);
}
void task2(int cnt)
{
    if (cnt > 0)
        printf("True"); else printf("False");
}
void run_task(int (*func)(int), int cnt)
{
    func(cnt);
}
int count_substrings(char *string, char *substring)
{
    int flag = 0, count = 0;
    for (int i = 0; *(string + i) != '\0'; i++)
    {
        for (int j = 0; *(substring + j) != '\0'; j++)
        {
            if (*(string + i + j) == *(substring + j))
                flag = 1;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag > 0)
            count++;
    }
    return count;
}
void input(int *var, char *str)
{

    printf("%s", str);
    while (!scanf("%d", var) || *var > 2 || *var < 0 || getchar() != '\n')
    {
        printf("Wrong input! Input again:");
        rewind(stdin);
    }
}
void getstr(char **string, int len)
{
    *string = (char *) malloc(sizeof(char));
    printf("Input string:\n");
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
