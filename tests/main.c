#include "malloc.h"

#include <unistd.h>

void print_pointer(void *ptr)
{
    const char hex_digits[] = "0123456789abcdef";
    char buffer[20];
    unsigned long value = (unsigned long)ptr;

    buffer[0] = '0';
    buffer[1] = 'x';
    for (int i = 0; i < sizeof(void *) * 2; i++)
    {
        buffer[2 + i] = hex_digits[(value >> ((sizeof(void *) * 2 - 1 - i) * 4)) & 0xf];
    }
    buffer[2 + sizeof(void *) * 2] = '\n';

    write(1, buffer, 2 + sizeof(void *) * 2 + 1);
}

int main()
{
    for (size_t i = 0; i < 2; i++)
    {
        void *test = malloc(10);
        print_pointer(test);
        free(test);
        test = malloc(20);
        write(1, "freed\n", 6);
    }
    return (0);
}
