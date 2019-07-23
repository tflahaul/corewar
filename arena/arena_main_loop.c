/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_main_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 10:50:45 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static void			ft_make_sure_each_process_is_alive(t_listhead const *head)
{
	t_listhead		*temp;
	t_listhead		*position;

	temp = (t_listhead *)head->next;
	while ((position = temp) != head)
	{
		temp = temp->next;
		if (((t_process *)ft_get_process(position))->live == 0)
			ft_list_pop(position, &ft_get_process);
		else
			((t_process *)ft_get_process(position))->live = 0;
	}
}

static void			ft_decode_next_instruction(t_process *node)
{
	uint8_t const	opcode = g_arena.arena[node->pc];

	if (__likely(opcode > 0 && opcode < 17))
		printf("OPC %#x\n", opcode);
}

static void			ft_exec_each_process(t_listhead const *head)
{
	t_process		*process;
	t_listhead		*position;

	position = (t_listhead *)head;
	while ((position = position->next) != head)
	{
		process = (t_process *)ft_get_process(position);
		if (__likely(process->cycle > 0))
			--process->cycle;
		else
		{
			if (process->funptr != 0)
				(*process->funptr)(process);
			ft_decode_next_instruction(process);
		}
	}
}

void				ft_arena_main_loop(t_listhead const *head)
{
	register int	index;
	register int	cycle;

	index = 0;
	cycle = CYCLE_TO_DIE;
	while (cycle > 0)
	{
		if (++index == cycle)
		{
			ft_make_sure_each_process_is_alive(head);
			if (ft_list_size(head) == 0)
				cycle -= CYCLE_DELTA;
			index = 0;
		}
		ft_exec_each_process(head);
	}
}
