/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:28:51 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/11 18:46:09 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (lst && f)
	{
		new_lst = (*f)(lst);
		lst = lst->next;
		while (lst)
		{
			ft_lst_push_back(&new_lst, (*f)(lst));
			lst = lst->next;
		}
		return (new_lst);
	}
	else
		return (NULL);
}
