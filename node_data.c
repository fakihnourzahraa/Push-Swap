/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:16:40 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/09 20:36:59 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	cost_analysis_a(t_node *a, t_node *b)
// {
// 	t_node	*n;

// 	if (a->target_node == NULL)
// 	{
// 		n = create_stack();
// 		n->index = 0;
// 	}
// 	else{
		
// 	}
// 	while (a)
// 	{
// 		a->push_cost = a->index;
// 		if (!(a->above_median))
// 			a->push_cost = stack_size(a) - (a->index);
// 		if (a->target_node && a->target_node->above_median)
// 			a->push_cost += a->target_node->index;
// 		else
// 			a->push_cost += stack_size(b) - a->target_node->index;
// 		a = a->next;
// 	}
// }

void	cost_analysis_a(t_node *a, t_node *b)
{
	int	n;

	while (a)
	{
		if (a->target_node == NULL)
			n = 0;
		else
			n = a->target_node->index;
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = stack_size(a) - (a->index);
		if (a->target_node && n)
			a->push_cost += n;
		else
			a->push_cost += stack_size(b) - n;
		a = a->next;
	}
}

void	set_cheapest(t_node *a)
{
	long	val;
	t_node	*node;

	val = LONG_MAX;
	while (a)
	{
		if (a->push_cost < val)
		{
			val = a->push_cost;
			node = a;
		}
		a = a->next;
	}
	node->cheapest = 1;
}

void	find_index(t_stack *a)
{
	int		i;
	t_node	*n;
	int		m;

	i = 0;
	n = a->top;
	m = stack_size(a->top) / 2;
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

	aa = a;
	bb = b;
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
			a->target_node = find_max(b);
		else
			a->target_node = target;
		aa = aa->next;
	}
}

void	set_target_b(t_node *b, t_node *a)
{
	t_node		*aa;
	t_node		*bb;
	t_node		*target;
	long		best;

	aa = a;
	bb = b;
	while (bb)
	{
		best = LONG_MAX;
		while (aa)
		{
			if (aa->val < bb->val && aa->val < best)
			{
				best = aa->val;
				target = aa;
			}
			aa = aa->next;
		}
		if (best == LONG_MAX)
			b->target_node = find_min(a);
		else
			bb->target_node = target;
		bb = bb->next;
	}
}
// Long so it takes int min
//make sure set targets are right
