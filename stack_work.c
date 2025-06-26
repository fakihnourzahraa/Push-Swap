/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:52:36 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/25 19:24:37 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_node s, long num)
{
	t_node	a;
}

int	check_errors(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '-' || s[i] != '+' || !iswhite(s[i])
			|| !(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}
//checks for suplicates in previous nodes

int	stack_intialization(char **argv, t_node s)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (check_errors(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (check_dup(s, num) == -1)
			return (0);
		i++;
	}
}

long	ft_atol(char *a)
{
	return (atol((const char *)a));
}