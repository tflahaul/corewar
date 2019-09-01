/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_read_write_memory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/01 19:02:14 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <corewar_compiler.h>

inline unsigned short	ft_safe_update_pc(int16_t pc, int16_t nb)
{
	return (pc + nb >= 0 ? MEMINDEX(pc + nb) : MEMINDEX(MEM_SIZE + (pc + nb)));
}

void					update_player_array(unsigned int addr, unsigned int id)
{
	t_warrior		*node;

	node = g_arena.warriors;
	while (node->next && id != (unsigned int)node->id)
		node = node->next;
	g_arena.arena_p[MEMINDEX(addr + 0)] = node->id_p;
	g_arena.arena_p[MEMINDEX(addr + 1)] = node->id_p;
	g_arena.arena_p[MEMINDEX(addr + 2)] = node->id_p;
	g_arena.arena_p[MEMINDEX(addr + 3)] = node->id_p;
}

void					ft_int_to_binarray(unsigned int addr, unsigned int nb)
{
	g_arena.arena[MEMINDEX(addr + 0)] = (nb >> 24) & 0xff;
	g_arena.arena[MEMINDEX(addr + 1)] = (nb >> 16) & 0xff;
	g_arena.arena[MEMINDEX(addr + 2)] = (nb >> 8) & 0xff;
	g_arena.arena[MEMINDEX(addr + 3)] = nb & 0xff;
}

int32_t					ft_binarray_to_int(unsigned int addr, unsigned int size)
{
	int32_t				value = 0;

	if (size == 1)
		value = g_arena.arena[MEMINDEX(addr)];
	else if (size == 2)
	{
		value |= g_arena.arena[MEMINDEX(addr + 0)] << 8;
		value |= g_arena.arena[MEMINDEX(addr + 1)];
		return ((int16_t)value);
	}
	else if (__likely(size == 4))
	{
		value |= (g_arena.arena[MEMINDEX(addr + 0)] << 24);
		value |= (g_arena.arena[MEMINDEX(addr + 1)] << 16);
		value |= (g_arena.arena[MEMINDEX(addr + 2)] << 8);
		value |= (g_arena.arena[MEMINDEX(addr + 3)]);
	}
	return (value);
}
