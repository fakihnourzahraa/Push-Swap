/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:56:37 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/08 21:58:01 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*f;

	f = a->top;
	while (f && f->next)
	{
		if (f->val > f->next->val)
			return (0);
		f = f->next;
	}
	return (1);
}

t_node	*find_last(t_stack *s)
{
	t_node	*a;

	if (!s)
		return (NULL);
	a = s->top;
	while (a && a->next)
	{
		a = a->next;
	}
	return (a);
}
