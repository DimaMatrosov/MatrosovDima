#include "ff.h"
int main() {
    int n;
    printf("input num of anime");
    num_element( &n);
    manga *anime = calloc(n, sizeof(manga));
    inputing_anime(anime, n);
    printing(n, anime);
    menu(anime, n);
    free_memory(anime, n);
    return 0;
}
