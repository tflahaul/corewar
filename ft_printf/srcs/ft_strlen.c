/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:25:46 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:25:46 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

size_t					ft_strlen(char const *str)
{
	register char		*ptr;

	ptr = (char *)str;
	if (!str || !(*str))
		return (0);
	while (*ptr)
		ptr++;
	return (ptr - str);
}
