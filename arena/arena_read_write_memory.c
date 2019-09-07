/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_read_write_memory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/28 13:21:53 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <corewar_compiler.h>

inline unsigned short	ft_safe_update_pc(int16_t pc, int16_t nb)
{
	return (pc + nb >= 0 ? MEMINDEX(pc + nb) : MEM_SIZE + (MEMINDEX(pc + nb)));
}

void					ft_int_to_binarray(int addr, int nb)
{
	g_arena.arena[NEG_MEM(addr + 0)] = (uint8_t)((nb & 0xff000000) >> 24);
	g_arena.arena[NEG_MEM(addr + 1)] = (uint8_t)((nb & 0x00ff0000) >> 16);
	g_arena.arena[NEG_MEM(addr + 2)] = (uint8_t)((nb & 0x0000ff00) >> 8 );
	g_arena.arena[NEG_MEM(addr + 3)] = (uint8_t)((nb & 0x000000ff));
}

int32_t					ft_binarray_to_int(int addr, int size)
{
	int32_t				value = 0;

	if (size == 1)
		value = g_arena.arena[NEG_MEM(addr)];
	else if (size == 2)
	{
		value |= g_arena.arena[NEG_MEM(addr + 0)] << 8;
		value |= g_arena.arena[NEG_MEM(addr + 1)];
		return ((int16_t)value);
	}
	else if (LIKELY(size == 4))
	{
		value |= (g_arena.arena[NEG_MEM(addr + 0)] << 24);
		value |= (g_arena.arena[NEG_MEM(addr + 1)] << 16);
		value |= (g_arena.arena[NEG_MEM(addr + 2)] << 8);
		value |= (g_arena.arena[NEG_MEM(addr + 3)]);
	}
	return (value);
}
