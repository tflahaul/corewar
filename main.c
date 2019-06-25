/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:08:13 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/25 21:34:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

__attribute__((deprecated)) // FONCTIONNE PAS COMME IL FAUT
static uint16_t			ft_parse_options(char const **argv, uint16_t index)
{
	if (strcmp((argv[index] + 1), "dump") == 0)
	{
		g_arena.options |= OPTION_DUMP;
		if (LIKELY(argv[++index] != NULL))
			g_arena.max_cycles = atoi(argv[index]);
		printf("dump = %u\n", g_arena.max_cycles);
	}
	else if (strcmp((argv[index] + 1), "n") == 0)
	{
		g_arena.options |= OPTION_NBR;
		if (LIKELY(argv[++index] != NULL))
			g_arena.options |= (atoi(argv[index]) & 0x7fu);
		printf("n = %u\n", g_arena.options & 0x7fu);
	}
	else
		printf("corewar: illegal option -- %s\n", argv[index] + 1);
	return (index);
}

static void				ft_parse_players(char const **argv)
{
	register uint16_t	index;

	index = 0;
	while (argv[++index] != NULL)
	{
		if (*argv[index] == '-')
			index = ft_parse_options(argv, index);
		else if (ft_valid_file_fmt(argv[index], FILE_FORMAT) == EXIT_SUCCESS)
			printf("new player\n");
		else
			exit(EXIT_FAILURE); // Point de sortie
	}
}

int						main(__unused int argc, char const **argv)
{
	ft_parse_players(argv);
	return (EXIT_SUCCESS);
}
