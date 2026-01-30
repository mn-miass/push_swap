#include "push_swap.h"

//no need to check if ther is somthing non number in the list or skiping spaces i already hundeled this in split
// the only thing left to do is to check if number is bigger them max_int or smaller then in int 
long long int ps_atoi(char *c)
{
    long long int    num;
    int         flag;

    num = 0;
    flag = 1;
    if (is_sign(*c))
    {
        if(*c == '-')
            flag = -1;
        c++;
    }
    while (is_digit(*c))
    {
        num = num * 10 + (*c - '0');
        c++;
    }
    return (num * flag);
}
