/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:00:44 by marvin            #+#    #+#             */
/*   Updated: 2025/06/21 21:00:44 by marvin           ###   ########.fr       */
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
    struct	s_stack_node *target_node;
    struct	s_stack_node *next;
    struct	s_stack_node *prev;
}   t_node;

typedef	struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

//errors
//stack

//utils
//commands
//algo



//libft

#endif