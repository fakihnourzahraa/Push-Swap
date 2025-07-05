/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:19:54 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/05 17:27:10 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	a->top = first->next;
	a->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(t_stack *b)
{
	rotate(b);
	write(1, "ra\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	// t_node	*s;

	// s = a->top;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
