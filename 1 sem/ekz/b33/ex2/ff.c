#include "ff.h"
void task1(int cnt)
{
    printf("Num: %d", cnt);
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
