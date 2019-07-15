/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/15 14:07:40 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include <arena.h>
#include <arena_errors.h>
#include <arena_memory.h>
#include <corewar_compiler.h>

static void				ft_display_arena(void)
{
	register uint16_t	index = 0;

	while (index < MEM_SIZE)
	{
		printf("%02hhx", g_arena.arena[index]);
		if (!(++index % 64))
			printf("\n");
		else
			printf(" ");
	}
}

int						main(int argc, char const **argv)
{
	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	ft_arena_load_warriors();
	if (g_arena.options & OPTION_V)
		ft_display_arena();
	return (EXIT_SUCCESS);
}
