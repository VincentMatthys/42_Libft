/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:38:30 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/14 21:11:03 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *big, char const *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little != 0)
	{
		while (big[i])
		{
			j = 0;
			while (little[j] && big[i + j] == little[j])
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
