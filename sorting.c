/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/05 16:49:16 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*f;
	t_node	*s;

	f = a->top;
	while (f)
	{
		s = f;
		while (s)
		{
			if (s->val > f->val)
				return (0);
			s = s->next;
		}
		f = f->next;
	}
	return (1);
}

t_node	*find_max(t_node *s)
{
	t_node	*a;
	t_node	*max;
	long	m;

	m = LONG_MIN;
	a = s;
	while (a)
	{
		if (a->val > m)
		{
			m = a->val;
			max = a;
		}
		a = a->next;
	}
	return (max);
}

t_node	*find_min(t_node *s)
{
	t_node	*a;
	t_node	*min;
	long	m;

	m = LONG_MAX;
	a = s;
	while (a)
	{
		if (a->val < m)
		{
			m = a->val;
			min = a;
		}
		a = a->next;
	}
	return (min);
}

void	sort_three(t_stack *a)
{
	t_node	*s;

	s = a->top;
	if (s == find_max(a->top))
		ra(a);
	else if (s->next == find_max(a->top))
		rra(a);
	if (s->val > s->next->val)
		sa(a);
}
//considers that a = 3

void	sorting(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		sa(a);
		return ;
	}
	if (a->size > 3)
		pb(a, b);
	if (a->size > 3)
	{
		// printf("fuck off");
		pb(a, b);
		// printf("after %d ", a->size);
	}
	while (a->size != 3 && !is_sorted(a))
	{
		push_descending(a, b);
	}
		printf("fuck off");
	sort_three(a);
		printf("fucked off");
	while (b->size)
	{
		push_ascending(a, b);
	}
	//sort_last(a);
}
//this is whats called by the main