/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:59:34 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/05 16:52:51 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	iswhite_(char *nptr)
{
	if ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		return (1);
	return (0);
}

static int	findbase(char *nptr)
{
	unsigned long	ans;

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

int	ft_atoi(char *nptr)
{
	long		ans;
	int			s;
	int			pow;
	char		*n;

	s = 1;
	ans = 0;
	n = nptr;
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
	return ((ans * s));
}
