/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_main_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/31 16:06:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

#define DECREASE_CTD(ctd)	do {(ctd) -= CYCLE_DELTA; live = 0;} while (0);

static inline int			ft_pop_dead_processes(t_listhead const *head)
{
	int						live;
	t_process				*prcs;
	t_listhead				*temp;
	t_listhead				*position;

	live = 0;
	temp = (t_listhead *)head->next;
	while ((position = temp) != head)
	{
		temp = temp->next;
		prcs = (t_process *)ft_get_process(position);
		if (prcs->live == 0)
		{
			ft_list_pop(position, &ft_get_process);
			--g_arena.processes;
		}
		else
		{
			live = live + prcs->live;
			prcs->live = 0;
		}
	}
	return (live);
}

void						ft_arena_main_loop(t_listhead *processes)
{
	int						live = 0;
	int						main_cycle = 0;
	register int			internal_cycle = 0;
	register int			ctd = CYCLE_TO_DIE;

	while (ctd > 0 && g_arena.processes > 0)
	{
		if (++main_cycle > (CYCLE_TO_DIE << 1) && ++internal_cycle > ctd)
		{
			if (ft_pop_dead_processes(processes) >= NBR_LIVE)
				DECREASE_CTD(ctd)
			else if (++live == MAX_CHECKS)
				DECREASE_CTD(ctd)
			internal_cycle = 0;
		}
		ft_for_each_process(processes);
		if (HAS_DUMP(g_arena.options) && main_cycle == g_arena.dump_cycles)
			break ;
	}
	ft_list_delete(processes, &ft_get_process);
	ft_hexdump_memory();
}
