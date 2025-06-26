/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:35:54 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/25 19:23:13 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**stack;

	if (argc < 2 || !argv[1][0])
		return (0);
	if (argc == 2)
	{
		stack = ft_split(argv[1], ' ');
		if (!stack)
			return (0);
	}
	argv++;
	
	
}
