/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_main_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:03 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/09 15:48:29 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

/* juste pour test, del later */
void						ft_arena_main_loop(t_listhead pclst[MAX_PLAYERS])
{
	t_listhead				*position;

	for (unsigned int i = 0; i < CHAMP_MAX_SIZE; ++i)
	{
		for (unsigned int j = 0; j < MAX_PLAYERS; ++j)
		{
			position = &(pclst[j]);
			while ((position = position->next) != &(pclst[j]))
				ft_fetch_instruction((t_process *)ft_get_process(position));
		}
	}
	ft_delete_proclist(pclst);
}

/*
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

void						ft_arena_main_loop(t_listhead pclst[MAX_PLAYERS])
{
	int						live;
	t_listhead				*position;
	register int			cycle = 0;
	register int			ctd = CYCLE_TO_DIE;

	live = 0;
	while (ctd > 0)
	{
		if (++cycle == ctd)
		{
			for (unsigned int index = 0; index < MAX_PLAYERS; ++index)
				if ((live += ft_pop_dead_processes(&(pclst[index]))) >= NBR_LIVE)
					ctd -= CYCLE_DELTA;
			cycle = 0;
			live = 0;
		}
		for (unsigned int idx = 0; idx < MAX_PLAYERS; ++idx)
		{
			position = &(pclst[idx]);
			while ((position = position->next) != &(pclst[idx]))
				ft_fetch_instruction((t_process *)ft_get_process(position));
		}
	}
	ft_delete_proclist(pclst);
}
*/
