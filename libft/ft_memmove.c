/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:00:49 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 18:31:37 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	long			i;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = (long)n;
	if (d > s)
	{
		while (--i >= 0)
			d[i] = s[i];
	}
	else
	{
		i = -1;
		while (++i < (long)n)
		{
			d[i] = s[i];
		}
	}
	return (dest);
}
