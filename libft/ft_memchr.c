/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:02:49 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 19:06:25 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = (unsigned char *) s;
	while (i < n)
	{
		if (*a == (unsigned char)c)
		{
			return (a);
		}
		i++;
		a++;
	}
	return (NULL);
}
