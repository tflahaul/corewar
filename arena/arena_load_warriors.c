/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_load_warriors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:06 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/02 09:38:19 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static int				ft_new_process(t_listhead *hd, int32_t id, int16_t pc, int idx)
{
	t_process			*process;

	if (__unlikely((process = (t_process *)malloc(sizeof(*process))) == NULL))
		return (EXIT_ERROR);
	ft_bzero(process, sizeof(*process));
	process->registers[1] = id;
	process->idx = idx;
	process->pc = pc;
	ft_list_push(&(process->list), hd);
	return (EXIT_SUCCESS);
}

int						ft_load_warriors_into_arena(t_listhead lst[MAX_PLAYERS])
{
	t_warrior			*node;
	register uint8_t	*arena;
	register uint32_t	idx;
	uint8_t const		*temp = g_arena.arena;
	uint32_t const		gap = (MEM_SIZE / g_arena.size);

	idx = 0;
	arena = g_arena.arena;
	node = g_arena.warriors;
	while ((node != NULL) && (idx < MAX_PLAYERS))
	{
		ft_memcpy(arena, node->program, node->size);
		ft_memset(g_arena.arena_p + gap * idx, idx + 1, node->size);
		if (ft_new_process(&(lst[idx]), node->id, (int16_t)(arena - temp), idx + 1) < 0)
			return (ft_puterror_memalloc_failure(&(lst[idx])));
		node = node->next;
		arena += gap;
		++idx;
	}
	return (EXIT_SUCCESS);
}
