/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:19:49 by vmatthys          #+#    #+#             */
/*   Updated: 2017/09/09 19:58:25 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bytecpy(char *d, char const *s, size_t len)
{
	while (len)
	{
		*d++ = *s++;
		len--;
	}
}

/*
** ------------------------------- DESCRIPTION ---------------------------------
** function copies n bytes from memory area src to memory area dst.  If dst and
** src overlap, behavior is undefined.  Applica tions in which dst and src
** might overlap should use ft_memmove instead.
** ------------------------------- PARAMETERS ----------------------------------
** void 		*dest: memory area to fill
** void const	*src: memory area to copy
** size_t		 n	: number of bytes to copy into dest
** --------------------------------- RETURN  -----------------------------------
** void *dest		: adress filled
** ------------------------------- EXPLANATIONS --------------------------------
** @ If dest src and n are aligned proceed to shortcut
** @ Else, do the obvious job until n = 0
** --------------------------------- APPARTE -----------------------------------
** When aligning data structures, is modullo (%) better than bytes comparaison ?
** (unsigned long long)cpy_b & (step - 1) == data structure alignment
** Indeed :
** if step = sizeof(unsigned long long) == 8 => 1.0.0.0
** Every multiple of this step has no 0 after the bit set to one.
** So, when substracting one to step : 0.1.1.1 and comparing it with the adress
** Adress is aligned when the result of & operator is 0
*/

void		*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t						step;
	unsigned long long			*d;
	unsigned long long const	*s;

	if (dest || src)
	{
		d = (unsigned long long int *)dest;
		s = (unsigned long long int const*)src;
		step = sizeof(unsigned long long int);
		if (!((unsigned long long)dest & (step - 1))
			&& !((unsigned long long)s & (step - 1))
			&& !(n & (step - 1)))
		{
			while (n)
			{
				*d++ = *s++;
				n -= step;
			}
		}
		ft_bytecpy((char *)d, (char const *)s, n);
		return (dest);
	}
	return (NULL);
}
