/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:36:24 by vmatthys          #+#    #+#             */
/*   Updated: 2017/08/20 16:43:19 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ------------------------------- DESCRIPTION ---------------------------------
** Initialize big_c and big_b to copy 8 bytes (as stored in big_c) at one time
** in big_b
** ------------------------------- PARAMETERS ----------------------------------
** unsigned char lsb_c	: least signifiant byte of c
** void *cpy_b			: cpy of the initial adress of (unsigned char *)b
** llu  **big_b			: adress of the big_b where to put 8 bytes at one time
** --------------------------------- RETURN  -----------------------------------
** llu	big_c			: lsb_c repeated over 8 bytes
** ------------------------------- EXPLANATIONS --------------------------------
** Example : with c = 0x2a (42 in decimal)
** First step : get least signifiant byte (002a)
** Second step : bmagic = 0x002a002a
** Third step : bmagic = 0x002a002a002a002a
** Last one : bmagic = 0x002a002a002a002a002a002a002a002a
** Do the shift in two steps to avoid warning if long has 32 bits.
*/

static unsigned long long	enhance_c(unsigned char lsb_c,
										void *cpy_b,
										unsigned long long **big_b)
{
	unsigned long long	big_c;

	big_c = lsb_c & 0xff;
	big_c = (big_c << 8) | big_c;
	big_c = (big_c << 16) | big_c;
	big_c = ((big_c << 16) << 16) | big_c;
	*big_b = (unsigned long long *)cpy_b;
	return (big_c);
}

/*
** ------------------------------- DESCRIPTION ---------------------------------
** ft_memset writes len bytes of value c (converted to an unsigned char) to the
** string b
** ------------------------------- PARAMETERS ----------------------------------
** void *b		: adress to fill
** int c		: byte value (least signifiant byte of c)
** size_t len	: number of bytes to copy into b
** --------------------------------- RETURN  -----------------------------------
** void *b		: adress filled
** ------------------------------- EXPLANATIONS --------------------------------
** @ If more than 8 byte, proceed to the shortcut.
** @@ First, Data structure alignment : we have to align cpy_b to a multiple of
** sizeof(big_c)
** @@ Second, until len is more than 8 bytes, copy
** @ Else, do the obvious job until len = 0
** --------------------------------- APPARTE -----------------------------------
** When aligning data structures, is modullo (%) better than bytes comparaison ?
** (unsigned long long)cpy_b & (step - 1) == data structure alignment
** Indeed :
** if step = sizeof(unsigned long long) == 8 => 1.0.0.0
** Every multiple of this step has no 0 after the bit set to one.
** So, when substracting one : 0.1.1.1 and comparing it with the adress
** Adress is aligned when the result of & operator is 0
*/

void						*ft_memset(void *b, int c, size_t len)
{
	unsigned char		lsb_c;
	unsigned char		*cpy_b;
	unsigned long long	big_c;
	unsigned long long	*big_b;
	size_t				step;

	lsb_c = 0xff & c;
	cpy_b = (unsigned char *)b;
	big_b = NULL;
	if ((step = sizeof(big_c)) && len >= step)
	{
		while ((unsigned long long)cpy_b & (step - 1) && len--)
			*cpy_b++ = lsb_c;
		big_c = enhance_c(lsb_c, cpy_b, &(big_b));
		while (len >= step)
		{
			*big_b++ = big_c;
			len -= step;
		}
	}
	if (big_b != NULL)
		cpy_b = (unsigned char *)big_b;
	while (len--)
		*cpy_b++ = lsb_c;
	return (b);
}
