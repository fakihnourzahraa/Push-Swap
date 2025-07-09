/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:46:38 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/07 20:04:18 by nfakih           ###   ########.fr       */
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
// b and a not empty refresh info b  prep for push and pa

// 	-> sort last 2 elements
	// 	-> while (b) push to a and rotate as needed
	// 	-> rotate till minimum is at top
void	move_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheap;

	if (!b->top)
	{
		pb(a, b);
		return ;
	}
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
//b might be empty

void	move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*n;

	if (!b->top)
		n = NULL;
	else
		n = b->top->target_node;
	prep_for_push(a, 'a', n);
	pa(a, b);
}
//a and b not empty

void	prep_for_push(t_stack *a, char n, t_node *top)
{
	int	v;

	if (!top)
		v = 1;
	else
		v = top->above_median;
	while (a != NULL && a->top != NULL && a->top != top)
	{
		if (n == 'a')
		{
			if (v)
				ra(a);
			else
				rra(a);
		}
		else if (n == 'b')
		{
			if (v)
				rb(a);
			else
				rrb(a);
		}
	}
}
//Parameter for stack name, combine them both here
