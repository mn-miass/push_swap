#include "checker_bonus.h"

char    *allocate_digit_bonus(char *c)
{
    int     i;
    char    *digits;

    i = 0;
    while (is_sign_bonus(c[i]) || is_digit_bonus(c[i]))
        i++;
    digits = malloc(i + 1);
    if (digits == NULL)
        return (NULL);
    i = 0;
    while (is_sign_bonus(c[i]) || is_digit_bonus(c[i]))
    {
        digits[i] = c[i];
        i++;
    }
    return (digits);
}


int     num_digits_bonus(char *c)
{
    int     num;
    bool    is_digit;

    is_digit = 0;
    num = 0;
    while (*c)
    {
        if ((is_digit_bonus(*c) || is_sign_bonus(*c)) && is_digit == 0)
        {
            num++;
            is_digit = 1;
        }
        else if (is_digit && is_sign_bonus(*c))
            return (-1);
        else if (is_space_bonus(*c))
            is_digit = 0;
        else if (is_invalid_bonus(*c))
            return (-1);
        c++;
    }
    return (num);
}


char    **ps_split_bonus(char *c)
{
    int size;
    int i;
    char    **splited;

    size = num_digits(c);
    i = 0;
    if (size == -1)
        return (NULL);
    splited = malloc((sizeof(char *) + 1) * size);
    if (splited == NULL)
        return (NULL);
    while (*c)
    {
        while (is_space_bonus(*c))
            c++;
        if (*c != '\0')
            splited[i] = allocate_digit(c);
        else
        {
            splited[i] = NULL;
            return (splited);
        }
        if (splited[i] == NULL)
            return (free_2d(splited), NULL);
        while (is_digit_bonus(*c) || is_sign_bonus(*c))
            c++;
        i++;
    }
    return (splited);
}

int main(int argc, char **argv)
{
    int i = 0;
    char **splited = ps_split(argv[1]);
    // printf("%s", splited[i]);
    while (splited[i])
    {
        printf("%s\n", splited[i]);
        i++;
    }
}