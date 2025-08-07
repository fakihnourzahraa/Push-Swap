/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/07 21:59:02 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*f;

	f = a->top;
	while (f->next)
	{
		if (f->val > f->next->val)
			return (0);
		f = f->next;
	}
	return (1);
}
int get_bit(int number, int bit_position)
{
    return (number >> bit_position) & 1;
}
void	sorting(t_stack	*a, t_stack	*b)
{
	int size;
	int	i;
	
	size = stack_size(a);
	i = 0;
	while (i < size)
	{
		if (get_bit(a->top->val, current) == 0)
		{
			pb(a, b);
		}
		else
			ra(a, b);
		i++;
	}
}