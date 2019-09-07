/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:25:05 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:25:05 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int						ft_strchr_index(char c, char *flags)
{
	int					index;

	index = 0;
	while (flags[index])
		if (flags[index++] == c)
			return (index);
	return (0);
}
