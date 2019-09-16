/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_load_warriors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:06 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/04 11:04:22 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static int				ft_new_process(t_listhead *hd, int32_t id, int16_t pc)
{
	t_process			*process;

	if (__unlikely((process = (t_process *)malloc(sizeof(*process))) == NULL))
		return (EXIT_ERROR);
	ft_bzero(process, sizeof(*process));
	process->registers[1] = id;
	process->pc = pc;
	process->head = hd;
	ft_list_push(&(process->list), hd);
	++g_arena.processes;
	return (EXIT_SUCCESS);
}

int						ft_load_warriors_into_arena(t_listhead *head)
{
	t_warrior			*node;
	register uint8_t	*arena;
	uint8_t const		*temp = g_arena.arena;
	uint32_t const		gap = (MEM_SIZE / g_arena.size);

	arena = g_arena.arena;
	node = g_arena.warriors;
	while (node != NULL)
	{
		ft_memcpy(arena, node->program, node->size);
		if (ft_new_process(head, node->id, (int16_t)(arena - temp)) < 0)
			return (ft_puterror_memalloc_failure(head));
		node = node->next;
		arena += gap;
	}
	return (EXIT_SUCCESS);
}
