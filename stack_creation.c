/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:52:30 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/26 15:53:35 by nfakih           ###   ########.fr       */
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
	stack->size = 0;
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
	new->above_median = false;
	new->cheapest = false;
	new->target_node = NULL;
	new->next = s->top;
	new->prev = NULL;
	if (s->top)
		s->top->prev = new;
	s->top = new;
	s->size++;
	return (1);
}

int	pop_stack(t_stack *s)
{
	int		val;
	t_node	*r;

	if (s->size == 0)
		return (0);
	r = s->top;
	val = r->val;
	s->top = s->top->next;
	if (s->top)
		s->top->prev = NULL;
	free(r);
	s->size--;
	return (val);
}

void	free_stack(t_stack *s)
{
	while (s->size)
	{
		pop_stack(s);
	}
	free(s);
}


