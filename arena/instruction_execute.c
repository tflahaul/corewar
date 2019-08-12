/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:58:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/12 14:39:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void					ft_each_process(t_listhead tab[MAX_PLAYERS])
{
	t_parameters		parameters;
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
				ft_fetch_instruction(process, &parameters);
				(*process->instruction.funptr)(process, &parameters);
			}
		}
	}
}
