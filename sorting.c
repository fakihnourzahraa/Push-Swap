/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/11 16:59:57 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b, int max)
{
	int	size;
	int	bit;
	int	i;

	bit = 0;
	while (bit < max)
	{
		size = stack_size(a);
		i = 0;
		while (i < size)
		{
			if (!((a->top->index >> bit) & 1))
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->top)
			pa(a, b);
		bit++;
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	if (a->top->next == find_min(a->top))
		sa(a);
	else if (a->top->next->next == find_min(a->top))
	{
		ra(a);
		ra(a);
	}
	else if (find_min(a->top) == find_last(a))
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->top != find_min(a->top))
	{
		if (find_min(a->top) == find_last(a))
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

int	base_cases(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return (1);
	else if (stack_size(a) == 2)
		sa(a);
	else if (stack_size(a) == 3)
		sort_three(a);
	else if (stack_size(a) == 4)
		sort_four(a, b);
	else if (stack_size(a) == 5)
		sort_five(a, b);
	else
		return (0);
	return (1);
}

void	sorting(t_stack *a, t_stack *b)
{
	int	max;
	int	bits;

	if (base_cases(a, b))
		return ;
	bits = 0;
	max = stack_size(a) - 1;
	refresh_index(a);
	while (max > 0)
	{
		max = max / 2;
		bits++;
	}
	radix_sort(a, b, bits);
}
