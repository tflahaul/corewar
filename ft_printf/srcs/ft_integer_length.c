/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:24:14 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:24:14 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

t_uint					ft_integer_length(long long nb)
{
	t_uint				length;

	length = 1;
	while ((nb /= 10))
		++length;
	return (length);
}
