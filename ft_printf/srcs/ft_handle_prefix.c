/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:34:08 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/06 11:34:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

char					*ft_handle_prefix(char c)
{
	char				*ptr;

	if (!(ptr = ft_strnew(3)))
		return (NULL);
	ptr[0] = '0';
	if (c == 'x' || c == 'X')
		ptr[1] = c;
	else
		ptr[1] = 0;
	ptr[2] = 0;
	return (ptr);
}
