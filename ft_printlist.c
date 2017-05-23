/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:05:47 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/13 17:24:11 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist(t_list *alst)
{
	if (alst)
	{
		while (alst)
		{
			ft_putendl((char *)(alst->content));
			ft_putnbr((int)(alst->content_size));
			write(1, "\n", 1);
			alst = alst->next;
		}
	}
}
