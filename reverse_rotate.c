/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:47:29 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/26 19:10:11 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *a)
{
	t_node	*first;
	t_node	*last;
	t_node	*b_last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	b_last = last->prev;
	b_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb", 3);
}

void	rra(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rra", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr", 3);
}
