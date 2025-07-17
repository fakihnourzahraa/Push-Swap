/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:52:36 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/17 16:44:32 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int *s, int t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t)
	{
		j = i + 1;
		while (j < t)
		{
			if (s[i] == s[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_errors(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '-' || s[i][j] == '+')
			j++;
		while (s[i][j])
		{
			if (!(s[i][j] >= '0' && s[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
//checks for unwanted chars

t_stack	*fill_stack(int *arr, int len)
{
	int		i;
	t_stack	*s;

	i = 0;
	s = create_stack();
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		if (!push_stack(s, arr[i]))
		{
			free_stack(s);
			return (NULL);
		}
		i++;
	}
	return (s);
}
//creates stack takes the arr and adds it to the stack

t_stack	*convert_to_stack(char **input)
{
	int		i;
	int		*arr;
	t_stack	*s;

	i = 0;
	s = NULL;
	if (!check_errors(input))
		return (NULL);
	arr = malloc(sizeof(int) * arr_len(input));
	if (!arr)
		return (NULL);
	while (input[i])
	{
		arr[i] = ft_atoi(input[i]);
		i++;
	}
	if (!check_dup(arr, i))
		return (free(arr), NULL);
	s = fill_stack(arr, i);
	if (!s)
		return (free(arr), NULL);
	return (free(arr), s);
}
//this is whats being called by the main
//it converts the input to an int array, checks for errors
//duplicates, creates stack, and pushes onto it

//here we're done with the input, we have stack a and are ready to sort