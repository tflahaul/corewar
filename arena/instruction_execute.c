/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:58:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/26 14:08:46 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arena.h>
#include <arena_process.h>

void					ft_for_each_process(t_listhead tab[MAX_PLAYERS])
{
	t_process			*process;
	t_listhead			*child;

	for (register int idx = (MAX_PLAYERS - 1); idx >= 0; --idx)
	{
		child = &(tab[idx]);
		while ((child = child->next) != &(tab[idx]))
		{
			process = (t_process *)ft_get_process(child);
			if (process->instruction.cycle == 0)
			{
				if (process->instruction.funptr != 0)
					(*process->instruction.funptr)(process, &(process->params));
				RESET_PROCESS(process);
				ft_fetch_instruction(process, &(process->params));
			}
			process->instruction.cycle--;
		}
	}
}
