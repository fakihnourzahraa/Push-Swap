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
	stack->size = 0;
	return (stack);
}
t_node	*find_last(t_stack *s)
{
	t_node	*a;

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
	new->index = 0;
	new->next = NULL;
	new->cheapest = 0;
	if (!s)
	{
		s->top = new;
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

int	stack_size(t_node *s)
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


