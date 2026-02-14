#include "checker_bonus.h"

int     ps_strlen(char *c)
{
    int i;

    i = 0;
    while (c[i])
        i++;
    return (i);
}

bool    is_empty(char *s)
{
    while (*s)
    {
        if (!is_space_bonus(*s))
            return 0;
    }
    return 1;
}

char    *ps_strdup(char *str)
{
    char    *dup;
    int     i;

    i = 0;
    dup = malloc(ps_strlen(str) + 1);
    if (dup == NULL)
        return (NULL);
    while (str[i])
    {
        dup[i] = str[i];
        i++; 
    }
    dup[i] = '\0';
    return (dup);
}

char    *ps_strjoin(char *str1, char *str2)
{
    char    *join;
    int     i;

    i = 0;
    if (is_empty(str1))
    {
        free(str1);
        error();
    }
    if (str1 == NULL)
        return (ps_strdup(str2));
    join = malloc(ps_strlen(str1) + ps_strlen(str2) + 1);
    if (join == NULL)
        return (NULL);
    while (str1[i])
    {
        join[i] = str1[i];
        i++;
    }
    while (*str2)
    {
        join[i] = *str2;
        i++;
        str2++;
    }
    join[i] = '\0';
    return (join);
}
