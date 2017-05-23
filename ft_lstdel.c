/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:12:59 by vmatthys          #+#    #+#             */
/*   Updated: 2016/12/03 17:58:37 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*to_del;

	if (alst && del)
	{
		while (*alst)
		{
			to_del = *alst;
			*alst = (*alst)->next;
			(*del)(to_del->content, to_del->content_size);
			free(to_del);
		}
	}
}
