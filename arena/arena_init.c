/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:06 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/14 16:43:46 by thflahau         ###   ########.fr       */
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
	uint8_t				*temp;
	t_warrior			*node;
	register uint32_t	idx;
	register uint8_t	*arena;

	idx = 0;
	temp = g_arena.arena;
	arena = g_arena.arena;
	node = g_arena.warriors;
	while ((node != NULL) && (idx < MAX_PLAYERS))
	{
		ft_memcpy(arena, node->program, node->size);
		if (ft_new_process(&(lst[idx]), node->id, (uint16_t)(arena - temp)) < 0)
			return (ft_puterror_memalloc_failure(&(lst[idx])));
		arena += ft_compute_gap_between_warriors();
		node = node->next;
		++idx;
	}
	return (EXIT_SUCCESS);
}
