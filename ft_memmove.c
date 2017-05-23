/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:41:48 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/08 21:18:35 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	size_t			i;

	i = 0;
	if ((int)((char const *)src - (char *)dest) > 0)
	{
		while (i < n)
		{
			*((char *)dest + i) = *((char const *)src + i);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*((char *)dest + n - 1 - i) = *((char const *)src + n - 1 - i);
			i++;
		}
	}
	return (dest);
}
