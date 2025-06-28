/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:16:40 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/28 18:34:04 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	cost_analysis(t_stack *a, t_stack *b)
{

}

void	set_cheapest(t_stack *a)
{

}
void	find_index(t_stack *a)
{
	int		i;
	t_node	*n;
	int		m;

	i = 0;
	n = a->top;
	m = stack_size(a) / 2;
	while (n)
	{
		n->index = i;
		if (i <= m)
			n->above_median = 0;
		if (i > m)
			n->above_median = 1;
		n = n->next;
		i++;
	}
}

void	set_target_a(t_node *a, t_node *b)
{
	t_node		*aa;
	t_node		*bb;
	t_node		*target;
	long		best;

	while (aa)
	{
		best = LONG_MIN;
		while (bb)
		{
			if (bb->val < a->val && bb->val < best)
			{
				best = bb->val;
				target = bb;
			}
			bb = bb->next;
		}
		if (best == LONG_MIN)
		{
			a->target_node = find_max(b);
		}
		else
			a->target_node = target;
		aa = aa->next;
	}
}
// Long so it takes int min

void	refresh_info_a(t_stack *a, t_stack *b)
{
	find_index(a);
	find_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}