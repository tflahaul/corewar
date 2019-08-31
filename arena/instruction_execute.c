/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:58:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/28 15:18:59 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void					ft_for_each_process(t_listhead *processes)
{
	t_process			*parent;
	t_listhead			*child;

	child = processes;
	while ((child = child->next) != processes)
	{
		parent = (t_process *)ft_get_process(child);
		if (parent->instruction.cycle == 0)
		{
			if (parent->instruction.funptr != 0)
				(*parent->instruction.funptr)(parent, &(parent->params));
			RESET_PROCESS(parent);
			ft_fetch_instruction(parent, &(parent->params));
		}
		else
			parent->instruction.cycle--;
	}
}
