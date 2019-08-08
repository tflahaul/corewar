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

inline void				ft_int32_to_binarray(unsigned int addr, unsigned int nb)
{
	register uint32_t	idx;
	uint32_t const		map[4] = {0xff000000u, 0x00ff0000u, 0x0000ff00u, 0xffu};

	idx = 0;
	while (idx < 4)
	{
		g_arena.arena[MEMINDEX(addr++)] = (uint8_t)((nb & map[idx]) >> idx * 8);
		++idx;
	}
}

inline int32_t			ft_binarray_to_int(unsigned int addr, unsigned int size)
{
	int32_t				value;
	register uint32_t	index;

	value = 0;
	index = 0;
	while (index++ < size)
	{
		value <<= __CHAR_BIT__;
		value |= g_arena.arena[MEMINDEX(addr++)];
	}
	return (value);
}
