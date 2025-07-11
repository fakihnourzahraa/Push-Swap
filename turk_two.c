/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:26:40 by nfakih            #+#    #+#             */
/*   Updated: 2025/07/11 17:35:24 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_info_a(t_stack *a, t_stack *b)
{
	find_index(a);
	find_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	refresh_info_b(t_stack *a, t_stack *b)
{
	find_index(a);
	find_index(b);
	set_target_b(a, b);
}
