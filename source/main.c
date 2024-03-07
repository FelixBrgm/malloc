#include "malloc.h"
int main()
{
    for (size_t i = 0; i < 10000 ; i++)
    {
        void *test = ft_malloc(10);
        printf("POINTER: %p\n", test);
    }

    printf("Capacity %i\n", storage.capacity);

    uint8_t asd = 0;
    activate_bit(&asd, 6);

    printf("VALUE: %zu\n", get_bit(asd, 7));
    printf("VALUE: %zu\n", get_bit(asd, 6));

    return (0);
}