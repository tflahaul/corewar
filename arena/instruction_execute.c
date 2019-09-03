/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:58:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/03 09:31:02 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void					ft_for_each_process(t_listhead tab[MAX_PLAYERS])
{
	t_process			*process;
	t_listhead			*child;
	register int		idx;

	idx = (MAX_PLAYERS - 1);
	while (idx >= 0)
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
			else
				process->instruction.cycle--;
		}
		idx--;
	}
}
