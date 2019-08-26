/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:54:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/16 13:37:59 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <corewar_options.h>
#include <corewar_compiler.h>

void					ft_print_help(char const **argv)
{
	(void)argv;
	if (ft_display_file("help.txt") != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void					ft_set_visualize(char const **argv)
{
	(void)argv;
	g_arena.options |= OPTION_V;
}

void					ft_set_print(char const **argv)
{
	(void)argv;
	g_arena.options |= OPTION_P;
}

void					ft_get_dump(char const **argv)
{
	if (__unlikely(*argv == NULL))
	{
		ft_puterror(NULLOPT);
		exit(EXIT_FAILURE);
	}
	if ((g_arena.dump_cycles = ft_atoi32_max(*argv)) <= 0)
	{
		ft_puterror(BADOPT);
		exit(EXIT_FAILURE);
	}
	g_arena.options |= OPTION_D;
}

void					ft_get_numb(char const **argv)
{
	if (__unlikely(*argv == NULL))
	{
		ft_puterror(NULLOPT);
		exit(EXIT_FAILURE);
	}
	if ((g_arena.value = ft_atoi32_max(*argv)) == EXIT_ERROR)
	{
		ft_puterror(BADOPT);
		exit(EXIT_FAILURE);
	}
	g_arena.options |= OPTION_N;
}
