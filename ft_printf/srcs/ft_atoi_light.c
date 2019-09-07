/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:23:45 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:23:45 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int						ft_atoi_light(char const *str)
{
	int					nb;
	int					ng;

	nb = 0;
	ng = 1;
	if (*str == 45)
		ng = *str++ - 46;
	while (*str > 47 && *str < 58)
		nb = nb * 10 + *str++ - 48;
	return (nb * ng);
}
