#include "checker_bonus.h"
#include <stdio.h>

void    print_list(t_list *a, char c)
{
    printf("%c : ", c);
    if (a == NULL)
     {
        printf("NULL\n");
        return ;
     }
    printf("%c -> size == %d\t", c, struct_size(a));
    while (a)
    {
        printf("%d", a -> value);
        if (a -> next)
            printf(" -> ");
        a = a -> next;
    }
    printf("\n");
}

void print_two_list(t_list *a, t_list *b)
{
    print_list(a, 'a');
    print_list(b, 'b');
}