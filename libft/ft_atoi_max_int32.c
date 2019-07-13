/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max_int32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:19:10 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/13 12:19:39 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <libft.h>

int32_t					ft_atoi_max_int32(char const *str)
{
	int64_t				nb;

	nb = 0;
	if (__builtin_expect((str[0] == 0), 0))
		return (0);
	while (*str == ' ')
		str++;
	if (__builtin_expect((*str == 0 || ISDIGIT(*str) == 0), 0))
		return (0);
	while (ISDIGIT(*str))
	{
		nb = nb * 10 + *str++ - '0';
		if (__builtin_expect((nb > INT32_MAX), 0))
			return (0);
	}
	return (__builtin_expect((*str != 0), 0) ? 0 : (int32_t)nb);
}
