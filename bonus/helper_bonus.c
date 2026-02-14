#include    "checker_bonus.h"

bool    is_digit_bonus(char c)
{
    return ((unsigned)(c - '0') < 10);
}

bool    is_space_bonus(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

bool    is_sign_bonus(char c)
{
    return(c == '+' || c == '-');
}

bool    is_invalid_bonus(char c)
{
    return (!is_digit_bonus(c) && !is_sign_bonus(c) && !is_space_bonus(c));
}
