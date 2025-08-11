/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:59:34 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/11 16:22:16 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	iswhite_(char *nptr)
{
	if ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		return (1);
	return (0);
}

unsigned long long	findbase(char *nptr)
{
	unsigned long long	ans;

	ans = 0;
	if (*nptr >= '0' && *nptr <= '9')
	{
		ans = 1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ans = ans * 10;
		nptr++;
	}
	return (ans);
}

long long	ft_atoi(char *n)
{
	long long			ans;
	long long			s;
	unsigned long long	pow;

	s = 1;
	ans = 0;
	while (iswhite_(n))
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			s = -1;
		n++;
	}
	pow = findbase(n);
	while (*n >= '0' && *n <= '9')
	{
		ans = ans + ((*n - '0') * pow);
		pow = pow / 10;
		n++;
	}
	if ((ans * s) > INT_MAX || (ans * s) < INT_MIN)
		return (2147483648);
	return (ans * s);
}
