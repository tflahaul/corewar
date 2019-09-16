/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:24:54 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:24:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

long double				ft_power(int power, long double nb)
{
	int					i;
	double				p;

	p = 1;
	i = 1;
	if (!power)
		return (1);
	while (i++ <= power)
	{
		if (power < 0)
			p = p / nb;
		else if (power > 0)
			p = p * nb;
	}
	return (p);
}
