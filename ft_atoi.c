/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:40:46 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/13 22:43:56 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int			n;
	int			sign;
	size_t		count;
	char const	*start;

	sign = 1;
	n = 0;
	count = 0;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	start = str;
	while ('0' <= *str && *str <= '9')
	{
		count++;
		if (count == 19 && ft_strcmp(start, "9223372036854775808") >= 0)
			return ((sign == 1) ? -1 : 0);
		n = 10 * n + (int)(*str++ - '0');
	}
	return (sign * n);
}
