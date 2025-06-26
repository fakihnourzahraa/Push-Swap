/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:19:21 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 19:07:09 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	char	*b;
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	a = (char *)s1;
	b = (char *)s2;
	r = (char *)malloc(ft_strlen(a) + ft_strlen(b) + 1);
	if (!r)
		return (NULL);
	while (a[i])
	{
		r[i] = a[i];
		i++;
	}
	while (b[j])
	{
		r[i + j] = b[j];
		j++;
	}
	r[i + j] = '\0';
	return (r);
}
