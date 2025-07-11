/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/09 21:33:15 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*f;
	t_stack	*s;

	f = a;
	while (f)
	{
		s = f;
		while (s)
		{
			if (s->val > f->val)
				return (0);
			s = s->next;
		}
		f = f->next;
	}
	return (1);
}

t_stack	*find_max(t_stack *s)
{
	t_stack	*a;
	t_stack	*max;
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

t_stack	*find_min(t_stack *s)
{
	t_stack	*a;
	t_stack	*min;
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
// 	if (a == find_max(a))
// 		ra(a);
// 	else if (a->next == find_max(a))
// 		rra(a);
// 	if (a->next != NULL && a->val > a->next->val)
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
	a = stack->val;
	b = stack->next->val;
	c = stack->next->next->val;
	printf("%d %d %d", a, b , c);
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

// void	sort_last(t_stack *a, t_stack *b)
// {
// 	t_stack	*n;

// 	n = a;
// 	while (b)
// 	{
// 		pa(a, b);
// 		if (a->val < )
// 		{

// 		}
// 	}
// 	while (a)
// 	{
// 		if (a != find_min(a))
// 			rra(a);
// 		n = n->next;
// 	}
// }
// 	-> sort last 2 elements
	// 	-> while (b) push to a and rotate as needed
	// 	-> rotate till minimum is at top
	

// static void print_stack(t_stack *s)
// {
//     if (!s || !s)
// 	{
//         printf("Stack is empty\n");
//         return;
//     }

//     t_stack *current = s;
//     while (current)
// 	{
//         printf("%d ", current->val);  // Print the value of the current node
//         current = current->next;        // Move to the next node
//     }
//     printf("\n");
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
	if (stack_size(a) > 3)
		pb(a, b);
	while (a != NULL && stack_size(a) != 3 && !is_sorted(a))
		push_descending(a, b);
	// sort_three(a);
	while (b && b->size)
		push_ascending(a, b);
	// sort_last(a);
}
// void	sorting(t_stack *a, t_stack *b)
// {
// 	if (is_sorted(a))
// 		return ;
// 	int i =0;
// 	printf("%d \n", i);
// 	i++;
// 	if (stack_size(a) == 2)
// 		return (sa(a));
// 	if (stack_size(a) == 3)
// 		return (sort_three(a));
// 	printf("%d \n", i);
// 	i++;
// 	if (stack_size(a) > 3)
// 		pb(a, b);
// 	printf("%d \n", i);
// 	i++;
// 	if (stack_size(a) > 3)
// 		pb(a, b);
// 	printf("%d \n", i);
// 	i++;
// 	while (a != NULL && stack_size(a) != 3 && !is_sorted(a))
// 		push_descending(a, b);
// 	printf("%d \n", i);
// 	i++;
// 	// sort_three(a);
// 	printf("%d \n", i);
// 	i++;
// 	while (b && b->size)
// 		push_ascending(a, b);
// 	printf("%d \n n", i);
// 	i++;
// 	//push_back(a, b);
// 	// sort_last(a);
// }
//this is whats called by the main

