/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_main_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/29 12:10:09 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

inline void					ft_pop_dead_processes(t_listhead const *head)
{
	t_listhead				*temp;
	t_listhead				*position;

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

void						ft_arena_main_loop(t_listhead const *head)
{
	t_listhead				*position;

	for (unsigned int index = 0; index < MEM_SIZE; ++index)
	{
		position = (t_listhead *)head;
		while ((position = position->next) != head)
			ft_decode_instruction((t_process *)ft_get_process(position));
	}
}
