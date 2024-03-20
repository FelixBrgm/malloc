#include "malloc.h"
int main()
{
    // for (size_t i = 0; i < 200 * 100; i++)
    // {
    //     void *test = ft_malloc(10);
    //     ft_free(test);
    //     test = ft_malloc(10);
    // }

    // printf("Capacity %i\n", storage.capacity);
    char *og = ft_malloc(100);
    og[4] = 'c';
    printf("OG: %p | %c\n", og, og[4]);
    char *test = ft_realloc(og, 400);

    printf("New: %p | %c\n", test, test[4]);
    return (0);
}