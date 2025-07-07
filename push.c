/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:36:14 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/07 19:02:35 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	if ((*b)->top)
		return ;
	push_stack(*a, (*b)->top->val);
	(*b)->size--;
	(*b)->top->val = 0;
}

void	pa(t_stack *a, t_stack *b)
{
	push(&a, &b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	// printf("push before: %d", b->size);
	push(&b, &a);
		// printf("push after: %d", b->size);
	write(1, "pb\n", 3);
}
