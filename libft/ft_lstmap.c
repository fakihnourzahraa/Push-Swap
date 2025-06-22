/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:06:04 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 19:06:04 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	adding(t_list **a, void *s, void (*del)(void *))
{
	t_list	*node;

	node = ft_lstnew(s);
	if (!node)
	{
		del(s);
		ft_lstclear(a, del);
		return (0);
	}
	ft_lstadd_back(a, node);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	void	*s;
	t_list	*d;

	if (!lst || !del || !f)
		return (NULL);
	a = NULL;
	d = lst;
	while (d)
	{
		s = f(d->content);
		if (!s)
		{
			ft_lstclear(&a, del);
			return (NULL);
		}
		if (!adding(&a, s, del))
			return (NULL);
		d = d->next;
	}
	return (a);
}
