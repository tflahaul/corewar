/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_main_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/26 14:38:01 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
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
		live += prcs->live;
		if (prcs->live == 0)
			ft_list_pop(position, &ft_get_process);
		else
			prcs->live = 0;
	}
	return (live);
}

static inline void			ft_reset_all(t_listhead const *head)
{
	t_listhead				*position;

	position = (t_listhead *)head;
	while ((position = position->next) != head)
		((t_process *)ft_get_process(position))->live = 0;
}

static inline int			ft_check_cycle_to_die(t_listhead lst[MAX_PLAYERS])
{
	int						live = 0;
	static int				kill;

	if (kill)
	{
		for (register unsigned int index = 0; index < MAX_PLAYERS; ++index)
			live += ft_pop_dead_processes(&(lst[index]));
	}
	else
	{
		for (register unsigned int index = 0; index < MAX_PLAYERS; ++index)
			ft_reset_all(&(lst[index]));
		kill = 1;
	}
	return (live >= NBR_LIVE ? EXIT_SUCCESS : EXIT_FAILURE);
}

void						ft_arena_main_loop(t_listhead pclst[MAX_PLAYERS])
{
	int						live = 0;
	register int			cycle = 0;
	register int			mainloop = 0;
	register int			ctd = CYCLE_TO_DIE;

	while (ctd > 0)
	{
		++mainloop;
		if (HAS_DUMP(g_arena.options) && ++mainloop >= g_arena.dump_cycles)
			break ;
		if (++cycle == ctd)
		{
			if (ft_check_cycle_to_die(pclst) == EXIT_SUCCESS)
			{
				ctd -= CYCLE_DELTA;
				live = 0;
			}
			else
			{
				++live;
				if (live == MAX_CHECKS)
				{
					ctd -= CYCLE_DELTA;
					live = 0;
				}
			}
			cycle = 0;
		}
		ft_for_each_process(pclst);
	}
	ft_delete_process_list(pclst);
	ft_hexdump_memory();
}
