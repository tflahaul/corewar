/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:54:44 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/06 14:54:45 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

char					*ft_itoa(long long n)
{
	long long			nb;
	int					len;
	char				*str;
	unsigned long long	value;

	nb = n;
	len = (n < 0 ? 2 : 1);
	while ((nb /= 10))
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = 0;
	if (n <= 0)
		str[0] = (n < 0 ? 45 : 48);
	value = ABS(n);
	while (value)
	{
		str[len--] = value % 10 + 48;
		value = value / 10;
	}
	return (str);
}
