#include "push_swap.h"
//should be helpfull to free the splited
void    free_2d(char **str)
{
    int i;

    i = 0;
    if (str == NULL)
        return;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    return;
}

void    error()
{
    write(1, "Error\n", 6);
    exit(0);
}