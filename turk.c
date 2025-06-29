/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:46:38 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/29 18:25:55 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_descending(t_stack *a, t_stack *b)
{
}
//refresh info a and , prep move a to b

void	push_ascending(t_stack *a, t_stack *b)
{
}
//refresh info b  prep for push and pa

// 	-> sort last 2 elements
	// 	-> while (b) push to a and rotate as needed
	// 	-> rotate till minimum is at top
void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheap;

	cheap = get_cheapest(*a);
	if (cheap->above_median && cheap->target_node->above_median)
		rr(a, b);
	else if (!(cheap->above_median) && !(cheap->target_node->above_median))
		rrr(a, b);
	prep_for_push(a, 'a', cheap);
	prep_for_push(b, 'b', cheap->target_node);
	pb(a, b);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	prep_for_push(t_stack *a, char n, t_node *top)
{
	while (a != top)
	{
		if (n == 'a')
		{
			if (top->above_median)
				ra(a);
			else
				rra(a);
		}
		else if (n == 'b')
		{
			if (top->above_median)
				rb(a);
			else
				rrb(a);
		}
	}
}
//Parameter for stack name, combine them both here
