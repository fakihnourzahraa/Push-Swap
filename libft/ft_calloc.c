/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:29:39 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 15:44:34 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*a;
	size_t		r;

	if (nmemb == 0 || size == 0)
	{
		a = (char *)malloc(1);
		return (a);
	}
	r = size * nmemb;
	if (nmemb > __SIZE_MAX__ / size)
		return (0);
	a = (char *)malloc(r);
	if (!a)
		return (NULL);
	ft_bzero(a, r);
	return (a);
}
