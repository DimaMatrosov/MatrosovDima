#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    char** str;
    printf("input num of strings\n");
    scanf_s("%d", &n);
    char* list = calloc(n  , sizeof(char));
    for (int i = 1;  i < n; i++)
    {
        *str = (char*) malloc(sizeof(char));
        printf("Input string:\n");
        char c;
        int len = 0;
        int j = 0;
        while ((c = getchar()) != EOF && c != '\n') {
            *(*str + j) = c;
            j++;
            len++;
            *str = (char *) realloc(*str, len);
        }


        while (*(*str + len) != '\0')
            len++;
        list[i] = calloc(len, sizeof(char));
    };
    for(i = 0; i < n; i++)
    {
        printf("%s  ", list[i]);
    }
    return 0;
}