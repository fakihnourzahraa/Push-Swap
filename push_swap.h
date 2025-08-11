/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:00:44 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 16:41:47 by nfakih           ###   ########.fr       */
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
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

//stack
int			stack_size(t_stack *a);
t_stack		*create_stack(void);
int			push_stack(t_stack *s, int val);
int			pop_stack(t_stack *s);
t_stack		*convert_to_stack(char **input);
void		free_stack(t_stack *s);
int			stack_size(t_stack *s);

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
long long	ft_atoi(char *nptr);
int			arr_len(char **input);
int			error_message(int r);
t_node		*find_last(t_stack *s);
int			ft_strcmp(char *s1, char *s2);

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

t_node		*find_max(t_node *s);
t_node		*find_min(t_node *s);
void		print_stack(t_stack *s);

int			ft_find_min(t_stack *a);
t_node		*find_max(t_node *s);
t_node		*find_min(t_node *s);
void		refresh_index(t_stack *a);
void		sort_three(t_stack *a);

#endif