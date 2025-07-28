/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/28 19:29:12 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*f;

	f = a->top;
	while (f->next)
	{
		if (f->val > f->next->val)
			return (0);
		f = f->next;
	}
	return (1);
}

void	sort_three(t_stack *a)
{
	if (a->top == find_max(a->top))
		ra(a);
	else if (a->top->next == find_max(a->top))
		rra(a);
	if (a->top->next != NULL && a->top->val > a->top->next->val)
		sa(a);
}
//considers that a = 3

void	sort_last(t_stack *a)
{
	t_node	*n;

	n = a->top;
	find_index(a);
	while (n->val != find_min(n)->val)
	{
		if (find_min(n)->above_median)
			ra(a);
		else
			rra(a);
	}
}

// void	sorting(t_stack *a, t_stack *b)
// {
// 	if (is_sorted(a))
// 		return ;
// 	if (stack_size(a) == 2)
// 		return (sa(a));
// 	if (stack_size(a) == 3)
// 		return (sort_three(a));
// 	if (stack_size(a) > 3)
// 		pb(a, b);
// 	if (stack_size(a) > 3 && !(is_sorted(a)))
// 		pb(a, b);
// 	while (a != NULL && stack_size(a) != 3)
// 		push_descending(a, b);
// 	sort_three(a);
// 	 print_stack(b);
// 	while (b && stack_size(b))
// 		push_ascending(a, b);
// 	sort_last(a);
// }

void	sorting(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (stack_size(a) == 2)
		return (sa(a));
	if (stack_size(a) == 3)
		return (sort_three(a));
	if (stack_size(a) > 3)
		pb(a, b);
	if (stack_size(a) > 3 && !(is_sorted(a)))
		pb(a, b);
	while (a != NULL && stack_size(a) != 3 && !is_sorted(a))
		push_descending(a, b);
	sort_three(a);
	while (b && stack_size(b))
		push_ascending(a, b);
	sort_last(a);
}
