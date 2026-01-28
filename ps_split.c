#include "push_swap.h"

// the split will take the join argument from ps_strjoin
// split will check for valid if non valid return null but i should free everything
// what are the non valid inoputs ? non integers some exceed integer limit duplicates
// i will only check for non int with this function i also added should be only one sign in num_digits

int    num_digits(char *c)
{
    int num;
    bool is_word;

    is_word = 0;
    num = 0;
    while (*c)
    {
        if (is_nonvalid(*c))
            return 0;
        else if (is_sign(*c) && (!is_digit(*(c + 1))))
            return 0;
        else if(is_sign(*c) && is_word == 1)
            return 0;
        else if ((is_digit(*c) || (is_sign(*c) && is_digit(*(c + 1)))) && is_word == 0)
        {
            is_word = 1;
            num++;
        }
        else if(is_space(*c) && is_word == 1)
            is_word = 0;
        c++;
    }
    return (num);
}

void    *free_split(char **str, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        free(str[j]);
        j++;
    }
    free (str);
    return(NULL);
}

int     num_fill(char *str)
{
    int i;

    if (str[0] == 0)
        return 0;
    i = 0;
    if (is_sign(str[i]))
        i++;
    while (is_digit(str[i]))
        i++;
    return (i);
}

char    **ps_split(char *s)
{
    char    **splited;
    int     count;
    int     j;

    if (s == NULL)
        return (NULL); // i guess its not really needed the check of joined string will be outside i can remove it later
    count = num_digits(s);
    if (count == 0)
        return (NULL);
    splited = malloc((count + 1) * sizeof(char *));
    if (splited == NULL)
        return (NULL); // make sure to free s after the null
    count = 0;
    j = 0;
    while (*s)
    {
        while (is_space(*s))
            s++;
        splited[j] = malloc(num_fill(s) + 1);
        if (splited[j] == NULL || num_fill(s) == 0)
            return (free_split(splited, j));
        while (is_digit(*s) || is_sign(*s))
        {
            splited[j][count] = *s;
            count++;
            s++;
        }
        splited[j][count] = 0;
        j++;
        count = 0;
    }
    splited[j] = NULL;
    return (splited);
}

int main(int argc, char **argv)
{
    char **splited = ps_split(argv[1]);
    printf("%p\n", splited);
}