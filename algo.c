/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:54:13 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/08 21:58:15 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack *a)
{
	t_node	*current;
	int		min;
	int		i;
	int		min_i;

	current = a->top;
	min = current->val;
	i = 0;
	min_i = 0;
	while (current)
	{
		if (current->val < min)
		{
			min = current->val;
			min_i = i;
		}
		i++;
		current = current->next;
	}
	return (min_i);
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

// void	refresh_index(t_stack *a)
// {
// 	t_node	*n;
// 	int		min;
// 	int		i;
// 	t_node	*second_min;

// 	i = 0;
// 	min = find_min(a->top)->val;
// 	find_min(a->top)->index = i;
// 	i++;
// 	while (i < stack_size(a))
// 	{
// 		n = a->top;
// 		second_min = n;
// 		while (n)
// 		{
// 			if (n->index == -1 && n->val < second_min->val && n->val > min)
// 				second_min = n;
// 			n = n->next;
// 		}
// 		second_min->index = i;
// 		i++;
// 		min = second_min->val;

// 	}
// }

void	refresh_index(t_stack *a)
{
	t_node	*current;
	int		index;
	t_node	*compare;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->val < current->val)
			{
				index++;
			}
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
//claude fix

void	sort_three(t_stack *a)
{
	if (a->top == find_max(a->top))
		ra(a);
	else if (a->top->next == find_max(a->top))
		rra(a);
	if (a->top->next != NULL && a->top->val > a->top->next->val)
		sa(a);
}
