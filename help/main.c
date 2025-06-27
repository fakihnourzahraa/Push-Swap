/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:35:54 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/26 16:48:59 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	char	**input;
	int		s;
	t_stack	*s;

	s = 0;
	if (argc < 2 || !argv[1][0])
		return (0);
	if (argc == 2)
	{
		s = 1;
		input = ft_split(argv[1], ' ');
		if (!input)
			return (error_message(0));
	}
	else
		input = &argv[1];
	if (!convert_to_stack(input, s))
	{
		if (s)
			free(input);
		return (0);
	}
	sorting(s);
	//here we have a stack of the input
	free (input);
}
//s to track if input should be freed