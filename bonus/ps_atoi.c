/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:24:35 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/15 19:36:38 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
