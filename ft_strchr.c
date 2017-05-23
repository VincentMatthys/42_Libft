/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:15:36 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/14 21:09:21 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	while ((char)c == 0 || *s)
	{
		if (*s == (char)c)
			return ((char *)(uintptr_t)s);
		s++;
	}
	return (((char)c == 0) ? (char *)(uintptr_t)s : NULL);
}
