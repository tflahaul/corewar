/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:06 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/16 13:51:01 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static inline uint32_t	ft_compute_gap_between_warriors(void)
{
	return ((uint32_t)(MEM_SIZE / ft_list_size_warrior()));
}

static int				ft_new_process(t_listhead *hd, int32_t id, uint16_t pc)
{
	t_process			*process;

	if (__unlikely((process = (t_process *)malloc(sizeof(*process))) == NULL))
		return (EXIT_ERROR);
	ft_bzero(process, sizeof(*process));
	process->registers[1] = id;
	process->head = hd;
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
	uint32_t const		gap = ft_compute_gap_between_warriors();

	idx = 0;
	arena = g_arena.arena;
	node = g_arena.warriors;
	while ((node != NULL) && (idx < MAX_PLAYERS))
	{
		ft_memcpy(arena, node->program, node->size);
		if (ft_new_process(&(lst[idx]), node->id, (uint16_t)(arena - temp)) < 0)
			return (ft_puterror_memalloc_failure(&(lst[idx])));
		node = node->next;
		arena += gap;
		++idx;
	}
	return (EXIT_SUCCESS);
}
