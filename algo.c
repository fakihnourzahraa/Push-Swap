/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:54:13 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/11 16:53:35 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	refresh_index(t_stack *a)
{
	t_node	*cur;
	int		index;
	t_node	*temp;

	cur = a->top;
	while (cur)
	{
		index = 0;
		temp = a->top;
		while (temp)
		{
			if (temp->val < cur->val)
			{
				index++;
			}
			temp = temp->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}

void	sort_three(t_stack *a)
{
	if (a->top == find_max(a->top))
		ra(a);
	else if (a->top->next == find_max(a->top))
		rra(a);
	if (a->top->next != NULL && a->top->val > a->top->next->val)
		sa(a);
}
