/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:15:00 by vmatthys          #+#    #+#             */
/*   Updated: 2016/12/03 20:50:14 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi2(char const *str)
{
	unsigned long	n;
	unsigned int	sign;

	sign = 0;
	n = 0;
	if (!str)
		return (0);
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str && (*str == '+' || *str == '-'))
		sign = (*str++ == '-') ? 1 : 0;
	while ('0' <= *str && *str <= '9')
	{
		if (sign == 0
			&& (unsigned long)(10 * n + (uint32_t)(*str - '0')) > 2147483647)
			return ((int)n);
		else if (sign == 1
			&& (unsigned long)(10 * n + (uint32_t)(*str - '0')) > 2147483648)
			return (-(int)n);
		else
			n = 10 * n + (uint32_t)(*str++ - '0');
	}
	return ((sign == 1) ? -(int)n : (int)n);
}
/*
** Permet de s'arrêter dès que l'int lu dépasse l'int max
*/
