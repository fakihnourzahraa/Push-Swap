/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/07 21:59:02 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_node	*find_max(t_node *s)
{
	t_node	*a;
	t_node	*max;
	long	m;

	m = LONG_MIN;
	a = s;
	while (a)
	{
		if (a->val > m)
		{
			m = a->val;
			max = a;
		}
		a = a->next;
	}
	return (max);
}

t_node	*find_min(t_node *s)
{
	t_node	*a;
	t_node	*min;
	long	m;

	m = LONG_MAX;
	a = s;
	while (a)
	{
		if (a->val < m)
		{
			m = a->val;
			min = a;
		}
		a = a->next;
	}
	return (min);
}


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


// void	refresh_index(t_stack *a)
// {
// 	t_node	*n;
// 	int		min;
// 	int		i;
// 	t_node	*second_min;

// 	i = 0;
// 	min = find_min(a->top)->val;
// 	find_min(a->top)->index = i;
// 	i++;
// 	while (i < stack_size(a))
// 	{
// 		n = a->top;
// 		second_min = n;
// 		while (n)
// 		{
// 			if (n->index == -1 && n->val < second_min->val && n->val > min)
// 				second_min = n;
// 			n = n->next;
// 		}
// 		second_min->index = i;
// 		i++;
// 		min = second_min->val;

// 	}
// }

void refresh_index(t_stack *a) {
    t_node *current = a->top;
    
    while (current) {
        int index = 0;
        t_node *compare = a->top;
        
        while (compare) {
            if (compare->val < current->val) {
                index++;
            }
            compare = compare->next;
        }
        current->index = index;  // This is the key!
        current = current->next;
    }
}

void	radix_sort(t_stack *a, t_stack *b, int max)
{
	int	size;
	int	bit;
	int i;

	bit = 0;
	while (bit < max)
	{
		size = stack_size(a);
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->top)
			pa(a, b);
		bit++;
	}
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
void	sort_four(t_stack *a, t_stack *b)
{
	while (a->top != find_min(a->top))
	{
		// if (find_min(a->top) == find_last(a))
		// 	rra(a);
		// else
			ra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}
void	sort_five(t_stack *a, t_stack *b)
{
		while (a->top != find_min(a->top))
	{
		// if (find_min(a->top) == find_last(a))
		// 	rra(a);
		// else
			ra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
int	base_cases(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return 1;
	if (stack_size (a) == 2)
		sa(a);
	else if (stack_size(a) == 3)
		sort_three(a);
	else if (stack_size(a) == 4)
		sort_four(a, b);
	else if (stack_size(a) == 5)
		sort_five(a, b);
	else
		return (1);
	return (0);
}
void sorting(t_stack *a, t_stack *b)
{
	int	max;
	int	bits;

	if (base_cases(a, b))
		return ;
	bits = 0;
	max = stack_size(a) - 1;
	refresh_index(a);
	while (max > 0)
	{
		max = max / 2;
		bits++;
	}
	radix_sort(a, b, bits);
} 
