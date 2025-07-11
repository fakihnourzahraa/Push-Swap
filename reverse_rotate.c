/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:47:29 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/27 17:43:36 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*b_last;

	if (!a || stack_size(a) < 2)
		return ;
	first = a;
	last = a;
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
	write(1, "rrb\n", 4);
}

void	rra(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rra\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
