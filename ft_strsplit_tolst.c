/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_tolst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:55:59 by vmatthys          #+#    #+#             */
/*   Updated: 2016/12/03 23:13:30 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnewstr(char const *str, size_t end)
{
	t_list	*new;

	new = ft_lstnew(str, end);
	((char *)(new->content))[end - 1] = 0;
	return (new);
}

t_list			*ft_strsplit_tolst(char const *str, char const *charset)
{
	t_list	*sp;
	t_list	*head;
	size_t	i;
	size_t	k;
	int		j;

	if (!str || !charset)
		return (NULL);
	i = 0;
	j = 0;
	head = NULL;
	while (str[i])
	{
		while (str[i] && ft_is_in_str(str[i], charset))
			i++;
		k = ft_wordlen(str + i, charset) + 1;
		if (j++ == 0 && str[i] && (sp = ft_lstnewstr(str + i, k)))
			head = sp;
		else if (str[i])
			sp = ft_lst_push_back(&sp, ft_lstnewstr(str + i, k));
		i = i + k - 1;
	}
	return ((*str) ? head : ft_lstnewstr("", 1));
}
