#include "malloc.h"

int main()
{
    (void *)malloc(1);
    printf("Pagesize: %i\n", storage.page_size);
    

    return (0);
}