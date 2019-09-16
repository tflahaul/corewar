/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_fp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:00:31 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/06 11:00:32 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void				ft_itoa_fp(long long nb, long long dec, char *str)
{
	char			*ptr;
	char			*decis;
	unsigned int	index;

	ptr = ft_itoa(nb);
	ft_strcpy(str, ptr);
	if (ptr != NULL)
		free((void *)ptr);
	ft_strcat(str, ".");
	index = ft_integer_length(dec);
	if (!(decis = ft_strnew(index + 1)))
		return ;
	decis[index] = 0;
	while (dec > 0)
	{
		decis[--index] = dec % 10 + 48;
		dec = dec / 10;
	}
	ft_strcat(str, decis);
	free((void *)decis);
}
