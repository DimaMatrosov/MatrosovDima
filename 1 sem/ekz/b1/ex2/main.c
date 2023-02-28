#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int i;
    //char **str = (char **) malloc(sizeof(char *));

    char *str = (char *) malloc(sizeof(char));
    printf("Input string:\n");
    char c;
    int n= 0;
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        *(str + i) = c;
        i++;
        n++;
        *str = (char *) realloc(str, n);
    }
    *(str + i) = '\0';
    int len = 0;
    while (*(str + len) != '\0')
        len++;
    int max = 0;
    int start;
    int word_len = 0;
    for ( i = 0; i <= len; i++)
    {
        word_len++;
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (word_len > max)
            {
                max = word_len;
                start = i - max;
            }
            word_len = 0;
        }
    }
    for (i=start; i < start+max; i++) // вывод самого длинного слова
        printf("%c", *(str+i));
    //printf("%d", max-1);


    return 0;
}
