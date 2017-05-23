/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:03:56 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/14 21:10:16 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little != 0)
	{
		while (i < l && big[i])
		{
			j = 0;
			while (i + j < l && little[j] && big[i + j] == little[j])
				j++;
			if (little[j] == 0)
				return ((char *)(uintptr_t)(big + i));
			i++;
		}
		return (NULL);
	}
	else
		return (char *)(uintptr_t)(big);
}
