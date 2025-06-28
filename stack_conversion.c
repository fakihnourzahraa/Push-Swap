/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:52:36 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/28 15:35:43 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_errors(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '-' || s[i] != '+' || !iswhite(s[i])
				|| (s[i] >= '0' && s[i] <= '9')))
			return (0);
		i++;
	}
	return (0);
}
//checks for unwanted chars

int	fill_stack(int *arr, t_stack *s)
{
	int		i;

	i = 0;
	s = create_stack();
	if (s == NULL)
		return (0);
	while (arr[i])
	{
		if (!push_stack(s, arr[i]))
		{
			free_stack(s);
			return (0);
		}
		i++;
	}
	return (1);
}
//creates stack takes the arr and adds it to the stack

int	convert_to_stack(char **input, t_stack *s)
{
	int		i;
	int		*arr;

	i = 0;
	if (!check_errors(input))
		return (error_message(0));
	arr = malloc(sizeof(int) * (arr_len(input) + 1));
	while (input[i])
	{
		arr[i] = ft_atoi(input[i]);
		i++;
	}
	arr[i] = '\0';
	if (!check_dup(arr))
	{
		free(arr);
		return (0);
	}
	if (!fill_stack(arr, s))
	{
		free(arr);
		return (0);
	}
	free (arr);
	return (1);
}
//this is whats being called by the main
//it converts the input to an int array, checks for errors
//duplicates, creates stack, and pushes onto it

//here we're done with the input, we have stack a and are ready to sort