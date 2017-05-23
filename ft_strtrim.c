/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:23:51 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/11 20:03:56 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int	ft_is_whitespace(char const c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static void			ft_escape_space(char const **p_start, char const **p_end)
{
	while (**p_start && ft_is_whitespace(**p_start))
		(*p_start)++;
	while (**p_end && ft_is_whitespace(**p_end))
		(*p_end)--;
}

static char			*ft_emptystr(void)
{
	char	*empty;

	if (!(empty = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	else
	{
		empty[0] = 0;
		return (empty);
	}
}

char				*ft_strtrim(char const *s)
{
	char const		*start;
	char const		*end;
	size_t			len;

	start = s;
	if (s && (len = ft_strlen(s)))
	{
		end = s + len - 1;
		if (end - start > 0)
			ft_escape_space(&start, &end);
		if (start == s && end == s + len - 1)
			return (ft_strdup(s));
		else if (end == s - 1)
			return (ft_emptystr());
		else
			return (ft_strsub(s, (unsigned int)(start - s),
			(size_t)(end - start + 1)));
	}
	else
		return (ft_emptystr());
}
