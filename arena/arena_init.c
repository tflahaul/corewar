/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:06 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 18:16:38 by thflahau         ###   ########.fr       */
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
	process->registers[0] = id;
	process->pc = pc;
	ft_list_push(&(process->list), hd);
	return (EXIT_SUCCESS);
}

int						ft_arena_load_warriors(t_listhead *head)
{
	t_warrior			*node;
	uint8_t				*temp;
	register uint8_t	*arena;

	arena = g_arena.arena;
	node = g_arena.warriors;
	temp = arena;
	while (node != NULL)
	{
		ft_memcpy(arena, node->program, node->size);
		if (ft_new_process(head, node->id, (uint16_t)(arena - temp)) < 0)
			return (ft_puterror_memalloc_failure(head));
		arena += ft_compute_gap_between_warriors();
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
