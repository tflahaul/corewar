/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:19:45 by thflahau          #+#    #+#             */
/*   Updated: 2018/11/17 15:19:45 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

char				*ft_strndup(char const *src, size_t len)
{
	char			*str;
	char			*ptr;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = str;
	while (len-- > 0)
		*str++ = *src++;
	*str = 0;
	return (ptr);
}
