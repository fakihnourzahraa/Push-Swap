/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:45:31 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 15:45:31 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;
	t_list	*t;

	if (!del || !lst)
		return ;
	a = *lst;
	while (a)
	{
		t = a->next;
		ft_lstdelone(a, del);
		a = t;
	}
	*lst = NULL;
}
