#include "push_swap.h"

bool is_space(char c)
{
    return (c == ' ' || c == '\t');
}

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_sign(char c)
{
    return (c == '-' || c == '+');
}

bool is_nonvalid(char c)
{
    return (!is_digit(c) && !is_space(c) && !is_sign(c));
}