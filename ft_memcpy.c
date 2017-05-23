/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:19:49 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/17 17:46:38 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest || src)
	{
		while (i < n)
		{
			*((unsigned char *)dest + i) = *((unsigned char const *)src + i);
			i++;
		}
		return (dest);
	}
	return (NULL);
}
