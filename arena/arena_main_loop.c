/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_main_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/02 12:20:11 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>
#include <gui.h>

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
		live += prcs->live;
		if (prcs->live == 0)
			ft_list_pop(position, &ft_get_process);
		else
			prcs->live = 0;
	}
	return (live);
}

static inline int			ft_check_cycle_to_die(t_listhead lst[MAX_PLAYERS])
{
	int						lives_in_current_period = 0;
	static int				first_check;

	if (first_check != 0)
	{
		lives_in_current_period += ft_pop_dead_processes(&(lst[0]));
		lives_in_current_period += ft_pop_dead_processes(&(lst[1]));
		lives_in_current_period += ft_pop_dead_processes(&(lst[2]));
		lives_in_current_period += ft_pop_dead_processes(&(lst[3]));
	}
	else
		first_check = 1;
	return (lives_in_current_period >= NBR_LIVE ? EXIT_SUCCESS : EXIT_FAILURE);
}

void						ft_arena_main_loop(t_listhead process_lst[MAX_PLAYERS], t_gui *data)
{
	int						live = 0;
	int						main_cycle = 0;
	register int			internal_cycle = 0;
	register int			ctd = CYCLE_TO_DIE;
	int						i;

	i = 0;
	while (ctd > 0)
	{
		if (HAS_DUMP(g_arena.options) && ++main_cycle >= g_arena.dump_cycles)
			break ;
		if (++internal_cycle >= ctd)
		{
			if (ft_check_cycle_to_die(process_lst) == EXIT_SUCCESS)
				DECREASE_CTD(ctd)
			else if (live++ >= MAX_CHECKS)
				DECREASE_CTD(ctd)
			internal_cycle = 0;
		}
		ft_for_each_process(process_lst);
		if (!data->running && !(i % data->speed))
			create_corewar_visual(data, i);
		i++;
	}
	while (!data->running)
		create_corewar_visual(data, i);
	ft_delete_process_list(process_lst);
	ft_hexdump_memory();
}
