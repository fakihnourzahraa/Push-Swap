/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:00:44 by marvin            #+#    #+#             */
/*   Updated: 2025/07/09 20:49:11 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					val;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

//stack
t_stack		*create_stack(void);
int			push_stack(t_stack *s, int val);
int			pop_stack(t_stack *s);
t_stack		*convert_to_stack(char **input);
void		free_stack(t_stack *s);
int			stack_size(t_node *s);

//algo
void		sorting(t_stack *a, t_stack *b);
int			is_sorted(t_stack *a);
t_node		*find_max(t_node *s);
t_node		*find_min(t_node *s);
void		sort_three(t_stack *a);

//helper
int			iswhite(char nptr);
int			ft_isdigit(int c);
char		**ft_split(char *str, char c);
int			ft_strlen(char *str);
int			ft_atoi(char *nptr);
int			arr_len(char **input);
int			error_message(int r);

//operations
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		rrb(t_stack *b);
void		rra(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		rb(t_stack *b);
void		ra(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

//sorting
void		refresh_info_a(t_stack *a, t_stack *b);
void		refresh_info_b(t_stack *a, t_stack *b);
void		cost_analysis_a(t_node *a, t_node *b);
void		set_cheapest(t_node *a);
void		find_index(t_stack *a);
void		set_target_a(t_node *a, t_node *b);
void		set_target_b(t_node *b, t_node *a);
void		push_descending(t_stack *a, t_stack *b);
void		push_ascending(t_stack *a, t_stack *b);
void		move_a_to_b(t_stack *a, t_stack *b);
void		move_b_to_a(t_stack *a, t_stack *b);
void		prep_for_push(t_stack *a, char n, t_node *top);

#endif