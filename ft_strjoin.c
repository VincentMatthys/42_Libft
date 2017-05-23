/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 06:31:04 by vmatthys          #+#    #+#             */
/*   Updated: 2016/12/05 23:00:24 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		i = 0;
		while (i < len && (*s1 || *s2))
		{
			join[i] = (*s1) ? *s1++ : *s2++;
			i++;
		}
		join[i] = 0;
		return (join);
	}
}
