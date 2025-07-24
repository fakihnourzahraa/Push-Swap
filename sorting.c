/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/24 17:14:08 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*f;
	
	f = a->top;
	while(f->next)
	{
		if (f->val > f->next->val)
			return (0);
		f = f->next;
	}
	printf("is sorted");
	return (1);
}

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

// void	sort_three(t_stack *a)
// {
// 	if (a->top == find_max(a->top))
// 		ra(a);
// 	else if (a->top->next == find_max(a->top))
// 		rra(a);
// 	if (a->top->next != NULL && a->top->val > a->top->next->val)
// 		sa(a);
// }
//considers that a = 3

void sort_three(t_stack *stack)
{
	int a;
	int b;
	int c;

	if (stack_size(stack) != 3)
		return ;
	a = stack->top->val;
	b = stack->top->next->val;
	c = stack->top->next->next->val;
	if (a < b && a < c && b > c)
	{
		rra(stack);
		sa(stack);
	}
	else if (a > b && a < c && b < c)
		sa(stack);
	else if (a < b && a > c && b > c)
		rra(stack);
	else if (a > b && a > c && b < c)
		ra(stack);
	else if (a > b && a > c && b > c)
	{
		ra(stack);
		sa(stack);
	}
}


// void	sort_last(t_stack *a)
// {
// 	t_node	*n;
// 	n = a->top;
// 	//printf("sort last\n");
// 	while (n) // a shouldnt be empty at the end
// 	{
// 		if (n->val != find_min(n)->val)
// 			rra(a);
// 		n = n->next;
// 	}
// 		// print_stack(a);
// }

void	sort_last(t_stack *a)
{
	t_node	*n;

	n = a->top;
	find_index(a);
	// printf("entered function, val %d %d", (find_min(n))->val, (find_min(n)->above_median));
	while (n->val != find_min(n)->val) // a shouldnt be empty at the end
	{
		if (find_min(n)->above_median)
			ra(a);
		else
			rra(a);
	}
// print_stack(a);
}
	// -> sort last 2 elements
	// 	-> while (b) push to a and rotate as needed
	// 	-> rotate till minimum is at top

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
	while (a != NULL && stack_size(a) != 3)
		push_descending(a, b);
	sort_three(a);
	 print_stack(b);
	while (b && stack_size(b))
		push_ascending(a, b);
	sort_last(a);
}

// void	sorting(t_stack *a, t_stack *b)
// {
// 	int	i = 0;
// 	print_stack(a);
// 	if (is_sorted(a))
// 		return ;
// 	if (stack_size(a) == 2)
// 		return (sa(a));
// 	if (stack_size(a) == 3)
// 		return (sort_three(a));
// 	 printf("index: %d \n", i++);
// 	if (stack_size(a) > 3)
// 		pb(a, b);
// 	printf("index: %d \n", i++);
// 	if (stack_size(a) > 3 && !(is_sorted(a)))
// 		pb(a, b);
// 	printf("index: %d \n", i++);
// 	while (a != NULL && stack_size(a) != 3 && !is_sorted(a))
// 		push_descending(a, b);
// 	printf("index: %d \n", i++);
// 	print_stack(a);
// 	print_stack(b);
// 	sort_three(a);
// 	printf("after");
// 	print_stack(a);
// 	print_stack(b);
// 	printf("index: %d \n", i++);
// 	while (b && stack_size(b))
// 		push_ascending(a, b);
// 	// print_stack(a);
// 	// print_stack(b);
// 	printf("index: %d \n", i++);
// 	sort_last(a);
// }
