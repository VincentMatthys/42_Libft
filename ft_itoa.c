/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:47:21 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/11 16:55:48 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoabasic(unsigned int n, unsigned int base, size_t neg)
{
	char			*s;
	char			*charset;
	unsigned int	cp;
	size_t			power;

	cp = n;
	power = 1;
	while ((cp = cp / base))
		power++;
	if (!(s = (char *)malloc(sizeof(char) * (power + 1 + neg))))
		return (NULL);
	else
	{
		charset = ft_strdup("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz");
		cp = n;
		s[power-- + neg] = 0;
		while ((s[power-- + neg] = charset[cp % base]) && cp)
			cp = cp / base;
		s[0] = (neg == 1) ? '-' : s[0];
		free(charset);
		return (s);
	}
}

char		*ft_itoa(int n)
{
	if (n >= 0)
		return (ft_itoabasic((unsigned int)n, 10, 0));
	else
		return (ft_itoabasic((unsigned int)-n, 10, +1));
}
