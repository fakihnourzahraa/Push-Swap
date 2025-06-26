/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:00:44 by marvin            #+#    #+#             */
/*   Updated: 2025/06/26 16:54:09 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					val;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

//errors
int			error_message(int r);

//stack
t_stack		*create_stack(void);
int			push_stack(t_stack *s, int val);
int			pop_stack(t_stack *s);
int			convert_to_stack(char **input, t_stack *s);
void		free_stack(t_stack *s);

//utils
//commands
//algo
int			sorting(t_stack *a);
//libft
static int	iswhite(char *nptr);
int			ft_isdigit(int c);
int			**ft_split(char *str, char c);
int			ft_strlen(char *str);

#endif