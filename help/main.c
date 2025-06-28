/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:35:54 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/28 15:32:55 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_input(int argc, char **argv, t_stack *s)
{
	t_stack	*s;
	char	**input;

	if (argc < 2 || !argv[1][0])
		return (0);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!(input))
			return (0);
	}
	else
		input = &argv[1];
	if (!convert_to_stack(input, &s))
	{
		if (argc == 2)
			free(input);
		return (0);
	}
	return (1);
}
//free input here, s so that we can use it as a parameter in sorting

int	main(int argc, char **argv)
{
	int		f;
	t_stack	*s;

	if (!process_input(argc, argv, s))
		error_message(0);
	sorting(s);
}
