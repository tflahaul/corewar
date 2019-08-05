/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_memory_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/29 12:10:09 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>

inline int32_t			ft_binarray_to_int32(unsigned int address)
{
	int32_t				value;
	register int		index;

	index = 0;
	while (index < 4)
	{
		value <<= __CHAR_BIT__;
		value |= g_arena.arena[MEMINDEX(address++)];
	}
	return (value);
}
