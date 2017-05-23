/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:56:55 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/14 22:21:34 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char const *delimiters)
{
	size_t	count;
	size_t	i;

	if (delimiters && s && s[0] != 0)
	{
		i = 1;
		count = (ft_is_in_str(s[0], delimiters) == 0) ? 1 : 0;
		while (s[i])
		{
			if (ft_is_in_str(s[i - 1], delimiters) == 1
					&& ft_is_in_str(s[i], delimiters) == 0)
				count++;
			i++;
		}
		return (count);
	}
	else
		return (0);
}
