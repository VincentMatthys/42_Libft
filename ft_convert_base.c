/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:12:52 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/15 09:51:13 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int			ch_b(char *base)
{
	int		*tab;
	size_t	i;

	i = 0;
	if (!base || !(tab = (int *)malloc(sizeof(*tab) * ('~' - ' ' + 1))))
		return (0);
	while (i < '~' - ' ' + 1)
		tab[i++] = 0;
	i = 0;
	while (base[i] != 0)
	{
		tab[(int)(base[i] - ' ')]++;
		if (tab[(int)(base[i] - ' ')] > 1)
			return (0);
		i++;
	}
	free(tab);
	tab = NULL;
	if (i < 2)
		return (0);
	else
		return (1);
}

static unsigned int			ch_e(char *nbr, char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!nbr || !base)
		return (0);
	while (nbr[i] != 0)
	{
		j = 0;
		while (base[j] != 0 && base[j] != nbr[i])
			j++;
		if (base[j] == 0)
			return (0);
		i++;
	}
	return (1);
}

static unsigned long long	ft_power(size_t nb, size_t power)
{
	unsigned long long result;
	unsigned long long t;

	t = (unsigned long long)nb;
	result = 1;
	if (power == 0)
		return (1);
	while (power > 0)
	{
		if (power % 2 == 1)
			result = t * result;
		power = power / 2;
		if (power > 0)
			t = t * t;
	}
	return (result);
}

char						*ft_convert_base(char *nbr,
	char *base_from, char *base_to)
{
	size_t				i;
	size_t				j;
	unsigned long long	s;
	char				*c;

	if ((s = 0) || !(ch_b(base_from) && ch_b(base_to) && ch_e(nbr, base_from)))
		return (NULL);
	i = 0;
	while (nbr[i] != 0 && !(j = 0))
	{
		while (base_from[j] != nbr[i])
			j++;
		s = s + j * ft_power(ft_strlen(base_from), ft_strlen(nbr) - i++ - 1);
	}
	i = 0;
	while ((j = 0) || (ft_power(ft_strlen(base_to), i) != 0
			&& s / ft_power(ft_strlen(base_to), i) != 0))
		i++;
	if (s > 2147483648 || !(c = (char *)malloc(sizeof(*c) * (i + 1))))
		return (NULL);
	while (i > 1 && (c[j++] = base_to[s / ft_power(ft_strlen(base_to), --i)]))
		s = s % ft_power(ft_strlen(base_to), i);
	c[j] = base_to[s];
	c[++j] = 0;
	return (c);
}
