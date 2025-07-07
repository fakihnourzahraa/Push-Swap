/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:35:54 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/29 16:20:35 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*process_input(int argc, char **argv)
{
	char	**input;
	int		i;
	t_stack	*b;

	if (argc < 2 || !argv[1][0])
		return (NULL);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!(input))
			return (NULL);
	}
	else
		input = &argv[1];
	b = convert_to_stack(input);
	// printf("%s", input[0]);
	// printf("%s", input[1]);
	// printf("%s", input[2]);
	if (argc == 2)
	{
		i = 0;
		while (input[i])
			free(input[i++]);
		free(input);
	}
	return (b);
}
//to string isnt working
//does it need to split only based on spaces or all white chars
//free input here, s so that we can use it as a parameter in sorting

int	main(int argc, char **argv)
{
	t_stack	*s;

	s = process_input(argc, argv);
	if (!s)
		return (error_message(0));
	sorting(s);
	return (0);
}
