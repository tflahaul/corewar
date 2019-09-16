/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:38:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/11 13:17:41 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t				ft_strlen(char const *str)
{
	char			*ptr;

	ptr = (char *)str;
	while (*ptr)
		++ptr;
	return (ptr - str);
}
