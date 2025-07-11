/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:35:54 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/11 19:04:36 by nfakih           ###   ########.fr       */
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

// #include <stdio.h>

// void print_stack(t_stack *s)
// {
//     if (!s || !s->top)
// 	{
//         printf("Stack is empty\n");
//         return;
//     }

//     t_node *current = s->top;
//     while (current)
// 	{
//         printf("%d ", current->val);  // Print the value of the current node
//         current = current->next;        // Move to the next node
//     }
//     printf("\n");
// }


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	// t_node *t;

	a = process_input(argc, argv);
	// printf("HIIIIII\n");
	// t = a->top;
	// while (t)
	// {
	// 	printf("%d ", t->val);
	// 	t = t->next;
	// }
	if (!a)
		return (error_message(0));
	b = create_stack();
	sorting(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
