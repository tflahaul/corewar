/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:54 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 12:28:52 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <smmintrin.h>
#define FLAG		(_SIDD_SWORD_OPS | _SIDD_MOST_SIGNIFICANT)

char				*ft_fast_strrchr(char const *str, int c)
{
	char			*ptr;
	__m128i			chunk;
	__m128i			*longword;
	__m128i const	set = _mm_setr_epi16(c, 0, 0, 0, 0, 0, 0, 0);

	ptr = NULL;
	longword = (__m128i *)str;
	while ('*')
	{
		chunk = _mm_loadu_si128(longword);
		if (_mm_cmpistrc(set, chunk, FLAG))
			ptr = (char *)longword + _mm_cmpistri(set, chunk, FLAG);
		else if (_mm_cmpistrz(set, chunk, FLAG))
			break ;
		++longword;
	}
	return (ptr);
}
