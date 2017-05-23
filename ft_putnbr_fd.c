/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:42:54 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/08 16:15:12 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
	else if (0 <= n && n < 10)
		ft_putchar_fd('0' + n % 10, fd);
	else
	{
		ft_putchar_fd('-', fd);
		if (!(-10 < n))
			ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd('0' - n % 10, fd);
	}
}
