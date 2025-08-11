/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:36:14 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/11 17:28:08 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	if (!src || !dest || !src->top)
		return ;
	temp = src->top;
	src->top = temp->next;
	if (src->top)
		src->top->prev = NULL;
	temp->next = dest->top;
	temp->prev = NULL;
	if (dest->top)
		dest->top->prev = temp;
	dest->top = temp;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
