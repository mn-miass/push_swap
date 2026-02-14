#include "checker_bonus.h"

void    error_bonus()
{
    write(2, "Error\n", 6);
    exit(1);
}

void    free_2d_bonus(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void    free_struct_bonus(t_list  *a)
{
    t_list  *tmp;

    tmp = a;
    while (a)
    {
        a = a ->next;
        free (tmp);
        tmp = a;
    }
}
