#include "./linked_list/linked_list.h"
#include <stdio.h>

void prints(void *ptr) {

    printf("VALUE: %i\n", *((int *) ptr));
}

int main() {

    int a = 3;
    int b = 5;
    int c = 7;

    t_list **list = NULL;

    t_list *temp = ft_lstnew(&a);
    list = &temp;

    ft_lstadd_back(list, ft_lstnew(&b));
    ft_lstadd_back(list, ft_lstnew(&c));

    ft_lstiter(*list, prints);



    return (0);
}