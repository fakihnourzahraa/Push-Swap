/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:26:40 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/28 19:29:16 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_info_a(t_stack *a, t_stack *b)
{
	find_index(a);
	find_index(b);
	set_target_a(a->top, b->top);
	cost_analysis_a(a, b);
	set_cheapest(a->top);
}

void	refresh_info_b(t_stack *a, t_stack *b)
{
	find_index(a);
	find_index(b);
	set_target_b(a->top, b->top);
}

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
