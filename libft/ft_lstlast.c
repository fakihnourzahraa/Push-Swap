/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:05:59 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 19:05:59 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*s;

	s = lst;
	if (!lst)
		return (NULL);
	while (s->next)
	{
		s = s->next;
	}
	return (s);
}
