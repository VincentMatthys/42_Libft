/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:52:24 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/19 10:55:17 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;

	dest_size = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	if (size == 0 && !dest)
		return (src_size);
	while (*dest)
	{
		dest_size++;
		dest++;
	}
	if (size <= dest_size)
		return (size + src_size);
	else
	{
		while (*src && size-- - dest_size - 1)
			*dest++ = *src++;
		*dest = 0;
		return (dest_size + src_size);
	}
}
