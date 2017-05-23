/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:55:23 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/13 15:09:33 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putbyte(char *tab, unsigned char const c)
{
	ft_putchar(tab[c >> 4]);
	ft_putchar(tab[c % 16]);
}

static void	ft_print_byte(unsigned char const c)
{
	(32 <= c && c <= 126) ? ft_putchar((char)c) : ft_putchar('.');
}

static void	ft_put_relativ_addr(char *count, size_t s)
{
	char *cpy;

	cpy = count;
	while ((s = s / 16))
		*(count-- + 6) = '0' + s % 16;
	ft_putstr(cpy);
	ft_putstr(": ");
}

static void	ft_print_mem_line(void *addr, size_t size, char *tab, size_t s)
{
	size_t		col;

	col = 0;
	while (col < 16)
	{
		if (s + col < size)
			ft_putbyte(tab, *((unsigned char *)addr + s + col));
		else
			write(1, "  ", 2);
		if (col % 2 == 1)
			write(1, " ", 1);
		col++;
	}
	col = 0;
	write(1, " ", 1);
	while (col < 16 && s + col < size)
		ft_print_byte(*((unsigned char *)addr + s + col++));
	write(1, "\n", 1);
}

void		*ft_print_memory(void *addr, size_t size)
{
	char		*tab;
	char		*count;
	size_t		s;

	if (addr)
	{
		s = 0;
		tab = ft_strdup("0123456789abcdef");
		count = ft_strdup("00000000");
		while (s < size)
		{
			ft_put_relativ_addr(count, s);
			ft_print_mem_line(addr, size, tab, s);
			s = s + 16;
		}
		ft_strdel(&tab);
		ft_strdel(&count);
	}
	return (addr);
}
