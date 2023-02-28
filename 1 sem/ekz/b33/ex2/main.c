#include "ff.h"
int main()
{
    char **string = (char **) malloc(sizeof(char *));
    char **substring = (char **) malloc(sizeof(char *));
    int len = 1;
    getstr(string, len);
    getstr(substring, len);
    int cnt = count_substrings(*string, *substring);
    task1(cnt);
    return 0;
}


