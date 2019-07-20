/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_main_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/20 15:20:18 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void					ft_arena_loop(t_listhead *head)
{
	t_process			*process;
	t_listhead			*position;

	position = head;
	while ((position = position->next) != head)
	{
		process = (t_process *)ft_get_process(position);
		if (process->cycle > 0)
			--process->cycle;
		else
			ft_fetch_decode_execute_instruction(process);
	}
}
