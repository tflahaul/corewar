/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_memory_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/14 15:37:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <corewar_compiler.h>

void					ft_int_to_binarray(unsigned int addr, unsigned int nb)
{
	g_arena.arena[MEMINDEX(addr + 0)] = (nb >> 24) & 0xff;
	g_arena.arena[MEMINDEX(addr + 1)] = (nb >> 16) & 0xff;
	g_arena.arena[MEMINDEX(addr + 2)] = (nb >> 8) & 0xff;
	g_arena.arena[MEMINDEX(addr + 3)] = nb & 0xff;
}

inline int32_t			ft_binarray_to_int(unsigned int addr, unsigned int sz)
{
	int32_t				value = 0;

	if (sz == 1)
		value = g_arena.arena[MEMINDEX(addr)];
	else if (sz == 2)
	{
		value |= g_arena.arena[MEMINDEX(addr + 0)] << 8;
		value |= g_arena.arena[MEMINDEX(addr + 1)];
	}
	else if (__likely(sz == 4))
	{
		value |= (g_arena.arena[MEMINDEX(addr + 0)] << 24);
		value |= (g_arena.arena[MEMINDEX(addr + 1)] << 16);
		value |= (g_arena.arena[MEMINDEX(addr + 2)] << 8);
		value |= (g_arena.arena[MEMINDEX(addr + 3)]);
	}
	return (value);
}
