/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:27:10 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/05 16:50:14 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	iswhite(char nptr)
{
	if ((nptr >= 9 && nptr <= 13) || nptr == 32)
		return (1);
	return (0);
}

int	error_message(int r)
{
	write(1, "Error\n", 6);
	return (r);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

int	arr_len(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}
