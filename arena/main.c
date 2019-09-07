/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/28 15:37:27 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

int						main(int argc, char const **argv)
{
	t_listhead			processes;

	if (UNLIKELY(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	ft_list_init_head(&processes);
	if (ft_load_warriors_into_arena(&processes) != EXIT_SUCCESS)
		return (EXIT_ERROR);
	ft_introduce_contestants();
	ft_arena_main_loop(&processes);
	ft_print_winner();
	return (EXIT_SUCCESS);
}
