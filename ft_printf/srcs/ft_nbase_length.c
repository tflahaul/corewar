/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbase_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:24:47 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:24:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

t_uint					ft_nbase_length(t_ulli nb, char const *base)
{
	t_uint				length;

	length = 1;
	while (nb > ft_strlen(base) - 1)
	{
		nb /= ft_strlen(base);
		++length;
	}
	return (length);
}
