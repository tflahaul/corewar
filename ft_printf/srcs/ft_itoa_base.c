/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:17:21 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/06 15:17:22 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

char					*ft_itoa_base(t_ulli nbr, int base)
{
	t_ulli				n;
	long long			i;
	char				*str;
	char const			fill[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (!nbr)
		return ("0");
	i = 0;
	n = (t_ulli)nbr;
	while (n > 0 && ++i)
		n = n / base;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = 0;
	while (i > 0)
	{
		str[--i] = fill[nbr % base];
		nbr = nbr / base;
	}
	return (str);
}
