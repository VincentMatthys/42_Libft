/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:31:07 by vmatthys          #+#    #+#             */
/*   Updated: 2016/12/05 23:10:40 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list **alst, void *neutral,
	void *(*f)(void *content1, void *content2))
{
	void	*seed;
	void	*tmp;
	t_list	*to_del;

	if (!alst || !f)
		return (NULL);
	if (*alst == NULL)
		return (NULL);
	seed = (*f)(neutral, (*alst)->content);
	while ((*alst)->next)
	{
		tmp = seed;
		seed = (*f)(seed, (*alst)->next->content);
		to_del = *alst;
		*alst = (*alst)->next;
		free(tmp);
		free(to_del->content);
		free(to_del);
	}
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
	return (seed);
}
