#include "push_swap.h"

int ps_strlen(char *s)
{
    int i;

    if (s == NULL)
        return 0;
    i = 0;
    while (s[i])
        i++;
    return (i);
}
