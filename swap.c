/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:17:43 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/27 17:42:33 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	int	*f;

	if (a->size < 2)
		return ;
	f = a->top->val;
	a->top->val = a->top->next->val;
	a->top->next->val = f;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}


