/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_main_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/08 10:36:05 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

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

static inline void			ft_decrease_ctd(int *ctd, int *live)
{
	*ctd -= CYCLE_DELTA;
	*live = 0;
}

void						ft_arena_main_loop(t_listhead *processes, int live)
{
	int						ctd;
	int						main_cycle;
	register int			internal_cycle;

	main_cycle = 0;
	internal_cycle = 0;
	ctd = CYCLE_TO_DIE;
	while (ctd > 0 && g_arena.processes > 0)
	{
		ft_for_each_process(processes);
		if (++main_cycle > CYCLE_TO_DIE && ++internal_cycle > ctd)
		{
			if (ft_pop_dead_processes(processes) >= NBR_LIVE)
				ft_decrease_ctd(&ctd, &live);
			else if (++live == MAX_CHECKS)
				ft_decrease_ctd(&ctd, &live);
			internal_cycle = 0;
		}
		if (HAS_DUMP(g_arena.options) && main_cycle == g_arena.dump_cycles)
		{
			ft_hexdump_memory();
			break ;
		}
	}
	ft_list_delete(processes, &ft_get_process);
}
