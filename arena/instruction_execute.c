/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:58:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/14 16:23:18 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arena.h>
#include <arena_process.h>

static inline void		ft_reset_process(t_process *process)
{
	process->instruction.funptr = (void *)0;
	ft_bzero(&(process->params), sizeof(t_parameters));
}

void					ft_each_process(t_listhead tab[MAX_PLAYERS])
{
	t_process			*process;
	t_listhead			*child;

	for (register unsigned int idx = 0; idx < MAX_PLAYERS; ++idx)
	{
		child = &(tab[idx]);
		while ((child = child->next) != &(tab[idx]))
		{
			process = (t_process *)ft_get_process(child);
			if (process->instruction.cycle > 0)
				process->instruction.cycle--;
			else
			{
				if (process->instruction.funptr != 0)
				{
					(*process->instruction.funptr)(process, &(process->params));
					ft_reset_process(process);
				}
				ft_fetch_instruction(process, &(process->params));
			}
		}
	}
}
