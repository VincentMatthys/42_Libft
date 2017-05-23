/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:09:09 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/08 16:14:29 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
	else if (0 <= n && n < 10)
		ft_putchar('0' + n % 10);
	else
	{
		ft_putchar('-');
		if (!(-10 < n))
			ft_putnbr(-(n / 10));
		ft_putchar('0' - n % 10);
	}
}
