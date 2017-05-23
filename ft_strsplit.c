/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:30:14 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/11 18:56:03 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_is_c(const char c, const char t)
{
	return (c == t);
}

static size_t		ft_count(char const *s, char const c)
{
	size_t	count;
	size_t	i;

	if (s[0] != 0)
	{
		i = 1;
		count = (ft_is_c(s[0], c) == 0) ? 1 : 0;
		while (s[i])
		{
			if (ft_is_c(s[i - 1], c) == 1
					&& ft_is_c(s[i], c) == 0)
				count++;
			i++;
		}
		return (count);
	}
	else
		return (0);
}

static size_t		ft_word(const char *str, const char c)
{
	size_t	wordlen;
	size_t	i;

	wordlen = 0;
	i = 0;
	while (str[i] && !ft_is_c(str[i], c))
	{
		wordlen++;
		i++;
	}
	return (wordlen);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**sp;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s || !(sp = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while ((k = 0) || s[i])
	{
		while (s[i] && ft_is_c(s[i], c))
			i++;
		if (s[i])
		{
			if (!(sp[j] = (char *)malloc(sizeof(char) *
							(ft_word(s + i, c) + 1))))
				return (NULL);
			while (s[i] && !ft_is_c(s[i], c))
				sp[j][k++] = s[i++];
			sp[j++][k] = 0;
		}
	}
	sp[j] = 0;
	return (sp);
}
