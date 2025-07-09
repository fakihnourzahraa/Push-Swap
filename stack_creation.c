/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:52:30 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/07 19:30:30 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc (sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

int	push_stack(t_stack *s, int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val = val;
	new->index = 0;
	new->push_cost = 0;
	new->above_median = 0;
	new->cheapest = 0;
	new->target_node = NULL;
	new->next = s->top;
	new->prev = NULL;
	if (s->top)
		s->top->prev = new;
	s->top = new;
	return (1);
}

int	pop_stack(t_stack *s)
{
	int		val;
	t_node	*r;

	if (!s || stack_size(s) == 0)
		return (0);
	r = s->top;
	val = r->val;
	s->top = s->top->next;
	if (s->top)
		s->top->prev = NULL;
	free(r);
	return (val);
}
//if val is 0...

void	free_stack(t_stack *s)
{
	if (!s)
		return ;
	while (stack_size(s))
	{
		pop_stack(s);
	}
	free(s);
}

int	stack_size(t_stack *a)
{
	int	i;
	t_node	*s;

	i = 0;
	if (!a)
		return (0);
	s = a->top;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}


