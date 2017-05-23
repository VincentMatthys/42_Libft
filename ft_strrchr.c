/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:58:33 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/14 21:10:38 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char const	*start;

	start = s - 1;
	while (*s)
		s++;
	while (s != start)
	{
		if (*s == (char)c)
			return ((char *)(uintptr_t)s);
		s--;
	}
	return (((char)c == 0) ? (char *)(uintptr_t)s : NULL);
}
