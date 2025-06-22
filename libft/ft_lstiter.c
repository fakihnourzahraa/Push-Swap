/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:05:49 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 19:05:49 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*a;

	a = lst;
	if (!lst || !f)
		return ;
	while (a)
	{
		f(a->content);
		a = a->next;
	}
}
