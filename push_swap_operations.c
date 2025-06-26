/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:17:43 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/26 19:11:00 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	*f;

	if (a->size < 2)
		return ;
	f = a->top->val;
	a->top->val = a->top->next->val;
	a->top->next->val = f;
}

void	sb(t_stack *b)
{
	int	*f;

	if (b->size < 2)
		return ;
	f = b->top->val;
	b->top->val = b->top->next->val;
	b->top->next->val = f;
}

void	ss(t_node *a, t_stack *b)
{
	sa(a);
	sa(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top)
		return ;
	push_stack(a, b->top->val);
	b->top->val = NULL;
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top)
		return ;
	push_stack(b, a->top->val);
	a->top->val = NULL;
}

