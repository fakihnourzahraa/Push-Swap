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
		if (!(s[i] == '-' || s[i] == '+' || iswhite(s[i])
				|| (s[i] >= '0' && s[i] <= '9')))
			return (0);
		i++;
	}
	return (0);
}
//checks for unwanted chars

t_stack	*fill_stack(int *arr)
{
	int		i;
	t_stack	*s;

	i = 0;
	s = create_stack();
	if (s == NULL)
		return (0);
	while (arr[i])
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
	t_stack	 *s;

	i = 0;
	if (!check_errors(input))
		return (NULL);
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
		return (NULL);
	}
	s = fill_stack(arr);
	free(arr);
	if (!s)
		return (NULL);
	return (s);
}
//this is whats being called by the main
//it converts the input to an int array, checks for errors
//duplicates, creates stack, and pushes onto it

//here we're done with the input, we have stack a and are ready to sort