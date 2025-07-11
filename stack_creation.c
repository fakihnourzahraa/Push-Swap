/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:52:30 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/11 18:38:42 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc (sizeof(t_stack));
	if (!stack)
		return (NULL);
	return (stack);
}
t_stack	*find_last(t_stack *s)
{
	t_stack	*a;

	a = s;
	while (a && a->next)
	{
		a = a->next;
	}
	return (a);
}
//stupid
int	push_stack(t_stack *s, int val)
{
	t_stack	*new;
	t_stack	*last;

	if (!s)
		return (0);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->val = val;
	new->next = NULL;
	new->cheapest = 0;
	if (!s)
	{
		s = new;
		new->prev = NULL;
	}
	else
	{
		last = find_last(s);
		last->next = new;
		new->prev = last;
	}
	return (1);
}

// int	push_stack(t_stack *s, int val)
// {
// 	t_node	*new;

// 	if (!s)
// 		return ;
// 	new = malloc(sizeof(t_node));
// 	if (!new)
// 		return (0);
// 	new->val = val;
// 	new->index = 0;
// 	new->push_cost = 0;
// 	new->above_median = 0;
// 	new->cheapest = 0;
// 	new->target_node = NULL;
// 	new->next = NULL;
// 	new->prev = NULL;
// 	if (s->top)
// 		s->top->prev = new;
// 	s->top = new;
// 	s->size++;
// 	return (1);
// }

int	pop_stack(t_stack *s)
{
	int		val;
	t_stack	*r;
	
	r = s;
	if (stack_size(s) == 0)
		return (0);
	val = s->val;
	s = s->next;
	if (s)
		s->prev = NULL;
	free(r);
	return (val);
}

void	free_stack(t_stack *s)
{
	while (stack_size(s))
	{
		pop_stack(s);
	}
	free(s);
}

int	stack_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}


