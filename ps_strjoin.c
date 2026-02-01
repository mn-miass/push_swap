#include "push_swap.h"

//the function does not free s1 (must do) -> free it after the strjoin return 
//the function check for the string that should be joined (str2) if its empty nothing will be added so just return s1
//if s1 is null the functionn will return dup of s2 no need to make a function seperatly it working fine
// the special about this function add spaces between arguments 
// dont check for errors just collect all arguments in one string
// return error only for fail
// possible error returning s1 that could be freed outsid the function hen s2 is empty to fix it i should skip the s2 check and put it outside

char    *ps_strjoin(char *s1, char *s2)
{
    char *join;
    int i;

    // if (s2 == NULL)
    //     return s1;
    if (s2[0] == '\0')
        return NULL;
    join = malloc(ps_strlen(s1) + ps_strlen(s2) + 2);
    if (join == NULL)
        return (NULL);
    i = 0;
    if (s1)
    {
        while (*s1)
        {
            join[i] = *s1;
            i++;
            s1++;
        }
        join[i] = ' ';
        i++;
    }

    while (*s2)
    {
        join[i] = *s2;
        i++;
        s2++;
    }
    join[i] = '\0';
    return (join);
}

