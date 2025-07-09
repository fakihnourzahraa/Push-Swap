/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/07 19:12:17 by nfakih           ###   ########.fr       */
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
	if (s->next != NULL && s->val > s->next->val)
		sa(a);
}
//considers that a = 3

void	sort_last(t_stack *s)
{
	t_node	*a;

	a = s->top;
	while (a)
	{
		if (s->top != find_min(a))
			rra(s);
		a = a->next;
	}
}

void	sorting(t_stack *a, t_stack *b)
{
	b = create_stack();
	if (is_sorted(a))
		return ;
	if (stack_size(a) == 2)
		return (sa(a));
	if (stack_size(a) > 3)
		pb(a, b);
	if (stack_size(a) > 3)
		pb(a, b);
	while (a && stack_size(a) != 3 && !is_sorted(a))
		push_descending(a, b);
	sort_three(a);
	while (b && a && stack_size(a))
		push_ascending(a, b);
	sort_last(a);
}
//if we get to here 100% theres a 


