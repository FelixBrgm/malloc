#include "malloc.h"

int main()
{
    printf("Pagesize: %i\n", getpagesize());
    void *test = NULL;
    int i = 0;
    while (i++ < 1)
    {
        test = malloc(10);
        printf("NXT %i\n", read_chars_as_short(test - 4));
        printf("COUNT %i\n", read_chars_as_short(test - 2));
        printf("MAIN: Test_ptr: %p\n", test);
    }
    void *asdf = NULL;
    i = 0;
    printf("\n\n\n\n\n\n");
    while (i++ < 1)
    {
        asdf = malloc(10);
        printf("TEst NXT %i\n", read_chars_as_short(test - 4));
        printf("COUNT %i\n", read_chars_as_short(test - 2));
        printf("MAIN: Test_ptr: %p\n", test);
        printf("------------\n");
        printf("NXT %i\n", read_chars_as_short(asdf - 4));
        printf("COUNT %i\n", read_chars_as_short(asdf - 2));
        printf("MAIN: asdf_ptr: %p\n", asdf);
    }

    return (0);
}