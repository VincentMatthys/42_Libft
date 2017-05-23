/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:03:58 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/14 22:10:52 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(const char *str, const char *delimiters)
{
	size_t	wordlen;
	size_t	i;

	wordlen = 0;
	if (str && delimiters)
	{
		i = 0;
		while (str[i] && !ft_is_in_str(str[i], delimiters))
		{
			wordlen++;
			i++;
		}
	}
	return (wordlen);
}
