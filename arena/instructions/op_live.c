/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:00:41 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/02 12:26:57 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void						op_live(t_process *process, t_parameters *par)
{
	t_warrior				*warrior;

	process->live++;
	if ((warrior = ft_get_warrior_from_id(par->tab[0])) != (void *)0)
	{
		if (g_arena.options & OPTION_P)
			ft_printf("A process is saying player %i is alive\n", par->tab[0]);
		g_arena.last_alive = warrior;
	}
	process->pc = MEMINDEX(process->pc + par->oplen + 1);
}
