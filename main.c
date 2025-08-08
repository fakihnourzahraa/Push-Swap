/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:35:54 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/07 21:53:25 by nfakih           ###   ########.fr       */
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

void	print_stack(t_stack *s)
{
	t_node	*current;

	if (!s || !s->top)
	{
		printf("Stack is empty\n");
		return ;
	}
	current = s->top;
	while (current)
	{
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = process_input(argc, argv);
	if (!a)
		return (error_message(0));
	b = create_stack();
	sorting(a, b);
	print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
