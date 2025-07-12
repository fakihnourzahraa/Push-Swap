/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:27 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/12 19:45:02 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*f;
	t_node	*s;

	f = a->top;
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
	// printf("%d %d %d", a, b , c);
	printf("sort three\n");
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

static void print_stack(t_stack *s)
{
    if (!s || !s->top)
	{
        printf("Stack is empty\n");
        return;
    }

    t_node *current = s->top;
    while (current)
	{
        printf("%d ", current->val);  // Print the value of the current node
        current = current->next;        // Move to the next node
    }
    printf("\n");
}

void	sort_last(t_stack *a)
{
	t_node	*n;

	n = a->top;
	printf("sort last\n");
	while (n) // a shouldnt be empty at the end
	{
		if (n->val != find_min(n)->val)
			rra(a);
		n = n->next;
	}
		// print_stack(a);
}
	// -> sort last 2 elements
	// 	-> while (b) push to a and rotate as needed
	// 	-> rotate till minimum is at top

// void	sorting(t_stack *a, t_stack *b)
// {
// 	if (is_sorted(a))
// 		return ;
// 	if (stack_size(a) == 2)
// 	 	return (sa(a));
// 	if (stack_size(a) == 3)
// 		return (sort_three(a));
// 	if (stack_size(a) > 3)
// 		pb(a, b);
// 	if (stack_size(a) > 3)
// 		pb(a, b);
// 	while (a != NULL && stack_size(a) != 3 && !is_sorted(a))
// 		push_descending(a, b);
// 	sort_three(a);
// }

void	sorting(t_stack *a, t_stack *b)
{
	// int	i = 0;
print_stack(a);
	if (is_sorted(a))
		return ;
	if (stack_size(a) == 2)
	{
		return (sa(a));
	}
	if (stack_size(a) == 3)
	{
		return (sort_three(a));
	}
	// printf("%d \n", i);
	// i++;
	if (stack_size(a) > 3)
		pb(a, b);
	// printf("%d \n", i);
	// i++;
	if (stack_size(a) > 3)
		pb(a, b);
	// printf("%d \n", i);
	// i++;
	while (a != NULL && stack_size(a) != 3 && !is_sorted(a))
		push_descending(a, b);
	// printf("%d \n", i);
	// i++;
	sort_three(a);
	// printf("%d \n", i);
	// i++;
	while (b && b->size)
		push_ascending(a, b);
	// printf("%d \n n", i);
	// i++;

	sort_last(a);
}
