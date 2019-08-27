/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/27 11:47:21 by thflahau         ###   ########.fr       */
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
		printf("Player %i '%s' has won the game\n", g_arena.last_alive->id, g_arena.last_alive->name);
}

static inline void		ft_introduce_contestants(void)
{
	printf("Introducing contestants...\n");
	for (t_warrior *node = g_arena.warriors; node; (node = node->next))
		printf("* Player %i, weighing %3i bytes, '%s'\n", node->id, node->size, node->name);
}

int						main(int argc, char const **argv)
{
	t_listhead			process_list[MAX_PLAYERS];

	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	ft_init_process_list(process_list);
	if (ft_load_warriors_into_arena(process_list) != EXIT_SUCCESS)
		return (EXIT_ERROR);
	if (g_arena.options & OPTION_V)
	{
		if (g_arena.options & ~OPTION_V)
			ft_puterror(OPTIGNORE);
		g_arena.options = OPTION_V;
		ft_hexdump_memory(); // goto visualizer
	}
	ft_introduce_contestants();
	ft_arena_main_loop(process_list);
	ft_print_winner();
	return (EXIT_SUCCESS);
}
