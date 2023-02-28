#include <stdio.h>
#include <stdlib.h>
int getstr(char **string, int len);
int str_len(char **str);
void str(char** string1, char** string2, int k);
int main()
{
    int len1, len2, k;
    char *A, *B;
    len1 = getstr( &A, len1);
    len2 = getstr( &B, len2);
    printf("\n");
    scanf_s("%d", &k);
    str( A, B,k);
    for(int i=0; i < len1; i++)
        printf("%c", *(A+i));
    for(int i=0; i < len2; i++)
        printf("%c", *(B+i));
    free(A);
    free(B);
    return 0;
}


int getstr(char **string, int len)
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
    printf_s("%d",len);
    //*(*string + i) = '\0';
    return len;
}
int str_len(char **str)
{
    int len = 0;
    while (*(*str + len) != '\0')
        len++;
    return len;
}
void str(char** string1, char** string2, int k){
    int length1 = str_len(string1);
    int length2 = str_len(string2);

    *string1 = (char*) realloc(*string1, (length1 + length2 + 1) * sizeof(char));
    (*string1)[length1] = 'a';
    (*string1)[length1+length2] = '\0';
    for (int j = 0; j < length2; j++) {
        for (int i = length1 + length2 - 1; i > k; i--) {
            (*string1)[i] = (*string1)[i - 1];
        }
    }
    for (int i = k; (*string2)[i-k] != '\0'; i++){
        (*string1)[i] = (*string2)[i-k];
    }
}