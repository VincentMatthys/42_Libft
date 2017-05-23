/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:46:16 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/08 16:12:47 by vmatthys         ###   ########.fr       */
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

char		*ft_itoabase(int n, int base)
{
	char			*s;

	if (2 <= base && base <= 62)
	{
		if (n >= 0)
			s = ft_itoabasic((unsigned int)n, (unsigned int)base, 0);
		else
			s = ft_itoabasic((unsigned int)-n, (unsigned int)base, 1);
		return (s);
	}
	else
		return (NULL);
}
