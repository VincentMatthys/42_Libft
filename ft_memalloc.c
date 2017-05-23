/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:44:27 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/08 09:14:09 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*allocated;
	size_t	i;

	if (!(allocated = (void *)malloc(size)))
		return (NULL);
	else
	{
		i = 0;
		while (i < size)
			((char *)allocated)[i++] = 0;
		return (allocated);
	}
}
