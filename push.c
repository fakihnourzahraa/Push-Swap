/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:36:14 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/28 18:41:54 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push(t_stack **a, t_stack **b)
// {
// 	if ((*b)->top)
// 		return ;
// 	push_stack(*a, (*b)->top->val);
// 	(*b)->size--;
// 	(*b)->top->val = 0;
// }

// void	push(t_stack **a, t_stack **b)
// {
// 	if (!(*b)->top)
// 		return ;
// 	push_stack(*a, (*b)->top->val);
// 	pop_stack(*b);
// }

void	push(t_stack *src, t_stack *dest)
{
	t_node	*node_to_move;

	if (!src || !dest || !src->top)
		return ;
	node_to_move = src->top;
	src->top = node_to_move->next;
	if (src->top)
		src->top->prev = NULL;
	node_to_move->next = dest->top;
	node_to_move->prev = NULL;
	if (dest->top)
		dest->top->prev = node_to_move;
	dest->top = node_to_move;
	src->size--;
	dest->size++;
}
//claude fix

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
