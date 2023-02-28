#include "hed.h"

/*int count_substrings(const char *string, const char *substring)
{

    int flag = 0, count = 0;

    for (int i = 0; *(string + i) != '\0'; ++i) {
        for (int j = 0; *(substring + j) != '\0'; ++j) {

            if (*(string + i + j) == *(substring + j)) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }

        if (flag) ++count;
    }

    return count;
}*/