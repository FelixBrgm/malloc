#include "malloc.h"

int main()
{
    printf("Pagesize: %i\n", getpagesize());
    void *test = malloc(600);
    printf("NXT %i\n", read_chars_as_short(test - 4));
    printf("COUNT %i\n", read_chars_as_short(test - 2));
    printf("MAIN: Test_ptr: %p\n", test);
    test = malloc(40);
    printf("MAIN: Test_ptr: %p\n", test);
    return (0);
}