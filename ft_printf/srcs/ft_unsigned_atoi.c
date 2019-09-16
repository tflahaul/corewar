/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:26:09 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:26:10 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

t_uint					ft_unsigned_atoi(char const *str)
{
	t_uint				nb;

	nb = 0;
	while (*str > 47 && *str < 58)
		nb = nb * 10 + *str++ - 48;
	return (nb);
}
