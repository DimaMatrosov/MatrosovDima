#include "hed.h"
int main()
{
    char **string = (char **) malloc(sizeof(char *));
    char **substring = (char **) malloc(sizeof(char *));
    int len = 1;
    getstr(string, len);
    getstr(substring, len);
    int cnt = count_substrings(*string, *substring);
    while (1)
    {
        printf("\nTasks:\n1. Count substrings\n2. Check if substring \n0. Stop\n\n");
        int task;
        input(&task, "Input task:");
        if (!task)
            break;
        printf("\n");
        if (task == 1)
            run_task((int (*)(int)) task1, cnt);
        else
            run_task((int (*)(int)) task2, cnt);
        printf("\n");
    }
    return 0;
}


