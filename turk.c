/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:46:38 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/27 18:46:15 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_descending(t_stack *a, t_stack *b)
{
	refresh_info_a(a, b);
	move_a_to_b(a, b);
}
//refresh info a and , prep move a to b

void	push_ascending(t_stack *a, t_stack *b)
{
	refresh_info_b(a, b);
	move_b_to_a(a, b);
}
//refresh info b  prep for push and pa

void	move_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheap;

	set_cheapest(a->top);
	cheap = a->top;
	if (cheap->above_median && cheap->target_node->above_median)
		rr(a, b);
	else if (!(cheap->above_median) && !(cheap->target_node->above_median))
		rrr(a, b);
	prep_for_push(a, 'a', cheap);
	prep_for_push(b, 'b', cheap->target_node);
	pb(a, b);
}
//there might be an issue in if else if check

void	move_b_to_a(t_stack *a, t_stack *b)
{
	prep_for_push(a, 'a', (b)->top->target_node);
	pa(a, b);
}

void	prep_for_push(t_stack *a, char n, t_node *top)
{
	if (!top)
		return ;
	while (a != NULL && a->top != NULL && a->top != top)
	{
		if (n == 'a')
		{
			if (find_min(a->top)->above_median)
				ra(a);
			else
				rra(a);
		}
		else if (n == 'b')
		{
			if (find_min(a->top)->above_median)
				rb(a);
			else
				rrb(a);
		}
	}
}
//add top && to..
//Parameter for stack name, combine them both here
