/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:40:46 by vmatthys          #+#    #+#             */
/*   Updated: 2017/08/20 18:31:45 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	size_t		i;
	int			res;
	int			sign;
	size_t		count;
	char const	*start;

	sign = 1;
	res = 0;
	count = 0;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		sign = (str[i++] == '-') ? -1 : 1;
	start = &(str[i]);
	while ('0' <= str[i] && str[i] <= '9' && ++count < 19)
		res = 10 * res + (int)(str[i++] - '0');
	if (count < 19)
		return (sign * res);
	if (ft_strncmp(start, "9223372036854775808", 19) > 0
			|| str[i] >= '8' || (str[i] && ft_isdigit(str[i + 1])))
		return ((sign == -1) ? 0 : -1);
	return (sign * (10 * res + (int)(str[i] - '0')));
}
