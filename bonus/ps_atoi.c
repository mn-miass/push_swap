#include "checker_bonus.h"

long long int	ps_atoi_bonus(char *c)
{
	long long	num;
	int			flag;

	num = 0;
	flag = 1;
	if (is_sign_bonus(*c))
	{
		if (*c == '-')
			flag = -1;
		c++;
	}
	while (is_digit_bonus(*c))
	{
		num = num * 10 + (*c - '0');
		if (num > (INT_MAX + (long long)1))
			return (num);
		c++;
	}
	return (num * flag);
}
