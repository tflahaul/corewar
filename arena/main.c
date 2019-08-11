/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 16:14:03 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static inline void		ft_print_winner(void)
{
	if (g_arena.last_alive)
		printf("Le joueur %i '%s' gagne la partie\n", g_arena.last_alive->id, g_arena.last_alive->name);
}

int						main(int argc, char const **argv)
{
	t_listhead			proclist[MAX_PLAYERS];

	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	ft_init_process(proclist);
	if (ft_load_warriors_into_arena(proclist) != EXIT_SUCCESS)
		return (EXIT_ERROR);
	if (g_arena.options & OPTION_V)
	{
		if (g_arena.options & ~OPTION_V)
			ft_puterror(OPTIGNORE);
		g_arena.options = OPTION_V;
		ft_hexdump_memory(); // goto visualizer
	}
	ft_arena_main_loop(proclist);
	ft_print_winner();
	return (EXIT_SUCCESS);
}
