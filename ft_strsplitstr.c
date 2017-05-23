/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:13:37 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/13 21:11:49 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplitstr(char const *s, char const *lim)
{
	char	**sp;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s || !lim || !(sp = (char **)malloc(sizeof(char *)
	* (ft_count_words(s, lim) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while ((k = 0) || s[i])
	{
		while (s[i] && ft_is_in_str(s[i], lim))
			i++;
		if (s[i])
		{
			if (!(sp[j] = (char *)malloc(sizeof(char) *
							(ft_wordlen(s + i, lim) + 1))))
				return (NULL);
			while (s[i] && !ft_is_in_str(s[i], lim))
				sp[j][k++] = s[i++];
			sp[j++][k] = 0;
		}
	}
	return ((sp[j] = 0) ? sp : sp);
}
