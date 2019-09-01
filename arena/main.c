/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/01 19:05:28 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

int						main(int argc, char const **argv)
{
	t_gui				data;
	t_listhead			process_list[MAX_PLAYERS];

	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	data.running = 1;
	if (g_arena.options & OPTION_V)
	{
		if (g_arena.options & ~OPTION_V)
			ft_puterror(OPTIGNORE);
		g_arena.options = OPTION_V;
		if (__unlikely(gui(&data)!= EXIT_SUCCESS))
			return (EXIT_ERROR);
	}
	ft_init_process_list(process_list);
	if (ft_load_warriors_into_arena(process_list) != EXIT_SUCCESS)
		return (EXIT_ERROR);
	ft_introduce_contestants();
	ft_arena_main_loop(process_list, &data);
	ft_print_winner();
	return (EXIT_SUCCESS);
}
