/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:24:41 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:24:42 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void					*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*ptr;
	unsigned char		uchar;

	uchar = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = uchar;
	return (s);
}
