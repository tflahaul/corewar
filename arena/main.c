/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/22 16:10:40 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

int						main(int argc, char const **argv)
{
	t_listhead			head;

	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	ft_list_init_head(&head);
	if (ft_load_warriors_into_arena(&head) != EXIT_SUCCESS)
		return (EXIT_ERROR);

///////////// visu SDL plus tard /////////////
	if (g_arena.options & OPTION_V)
	{
		if (g_arena.options & ~OPTION_V)
			ft_puterror(OPTIGNORE);
		g_arena.options = OPTION_V;
		ft_hexdump_memory(); // goto visualizer
	}
//////////////////////////////////////////////

	ft_arena_main_loop(&head);
	ft_list_delete(&head, &ft_get_process);
	return (EXIT_SUCCESS);
}
