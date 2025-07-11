/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:19:54 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/09 19:39:29 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || stack_size(a) < 2 || !a)
		return ;
	first = a;
	last = a;
	while (last->next)
		last = last->next;
	a = first->next;
	if (a)
		a->prev = NULL;
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
	// t_stack	*s;

	// s = a->top;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
