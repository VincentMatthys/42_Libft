/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 22:05:27 by vmatthys          #+#    #+#             */
/*   Updated: 2017/09/06 00:10:03 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*ft_zero_byte(unsigned long long *big_s,
	unsigned long long low_word, unsigned long long high_word, size_t step)
{
	size_t				i;
	unsigned long long	big_word;
	char const			*zero_word;

	while (1)
	{
		big_word = *big_s;
		if ((big_word - low_word) & (~big_word & high_word))
		{
			i = 0;
			zero_word = (char const *)(big_s);
			while (i < 4)
				if (!zero_word[i++])
					return (zero_word + i - 1);
			if (step > 4)
				while (i < 8)
					if (!zero_word[i++])
						return (zero_word + i - 1);
		}
	}
}

/*
** ------------------------------- DESCRIPTION ---------------------------------
** ft_strlen find length of string
** ------------------------------- PARAMETERS ----------------------------------
** char const *s		: string
** --------------------------------- RETURN  -----------------------------------
** size_t				: length of s
** ------------------------------- EXPLANATIONS --------------------------------
** @ First, Data structure alignment : we have to align cpy_s to a multiple of
** sizeof(big_s)
** @@ if unsigned long long is more than 4 bytes, extend the search to 8 bytes
** @ search for zero byte
** --------------------------------- APPARTE -----------------------------------
** When aligning data structures, is modullo (%) better than bytes comparaison ?
** (unsigned long long)cpy_b & (step - 1) == data structure alignment
** Indeed :
** if step = sizeof(unsigned long long) == 8 => 1.0.0.0
** Every multiple of this step has no 0 after the bit set to one.
** So, when substracting one : 0.1.1.1 and comparing it with the adress
** Adress is aligned when the result of & operator is 0
*/

size_t				ft_strlen(char const *s)
{
	unsigned long long	*big_s;
	union u_str_union	cpy_s;
	size_t				step;

	step = sizeof(big_s);
	cpy_s.const_str = s;
	while ((unsigned long long)cpy_s.str & (step - 1))
		if (!(*cpy_s.str++))
			return (size_t)(cpy_s.str - s - 1);
	big_s = (unsigned long long*)cpy_s.str;
	if (step > 4)
	{
		return (size_t)(ft_zero_byte(big_s,
			(0x01010101UL << 16) << 16 | 0x01010101UL,
			(0x80808080UL << 16) << 16 | 0x80808080UL,
			step) - s);
	}
	return (size_t)(ft_zero_byte(big_s, 0x01010101UL, 0x80808080UL, step) - s);
}
