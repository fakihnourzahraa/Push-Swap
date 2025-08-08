/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:52:30 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/30 17:49:06 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	stack_size(t_stack *a)
{
	int		i;
	t_node	*s;

	i = 0;
	s = a->top;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc (sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

t_node	*find_last(t_stack *s)
{
	t_node	*a;

	if (!s)
		return (NULL);
	a = s->top;
	while (a && a->next)
	{
		a = a->next;
	}
	return (a);
}

int	push_stack(t_stack *s, int val)
{
	t_node	*new;
	t_node	*last;

	if (!s)
		return (0);
	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val = val;
	new->index = -1;
	new->next = NULL;
	if (s->top)
	{
		last = find_last(s);
		last->next = new;
		new->prev = last;
	}
	else
	{
		s->top = new;
		new->prev = NULL;
	}
	return (1);
}

int	pop_stack(t_stack *s)
{
	int		val;
	t_node	*r;

	if (!stack_size(s))
		return (0);
	r = s->top;
	val = r->val;
	s->top = s->top->next;
	if (s->top)
		s->top->prev = NULL;
	free(r);
	return (val);
}

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
