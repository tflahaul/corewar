/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:08:13 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/24 21:09:58 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <string.h>
#include <stdio.h>

#define DUMPMASK		0x3f80u
#define DUMP_SHIFT		0x7u
#define EXTRACT_DUMP(x)	((x & DUMPMASK) >> DUMP_SHIFT)

// Current dump and players number values cannot exceed 127 as they are
// written on 7 bits
static uint16_t			ft_parse_options(char const **option, uint16_t index)
{
	if (strcmp((option[index] + 1), "dump") == 0)
	{
		g_arena.options |= OPTION_DUMP;
		if (LIKELY(option[++index] != NULL))
			g_arena.options |= ((atoi(option[index]) & 0x7fu) << DUMP_SHIFT);
		printf("dump = %u\n", EXTRACT_DUMP(g_arena.options));
	}
	else if (strcmp((option[index] + 1), "n") == 0) // unsafe
	{
		g_arena.options |= OPTION_NBR;
		if (LIKELY(option[++index] != NULL))
			g_arena.options |= (atoi(option[index]) & 0x7fu);
		printf("n = %u\n", g_arena.options & 0x7fu);
	}
	return (index);
}

static void				ft_parse_players(char const **argv)
{
	register uint16_t	index;

	index = 0;
	while (argv[++index] != NULL)
		if (*argv[index] == '-')
			index = ft_parse_options(argv, index);
}

int						main(__unused int argc, char const **argv)
{
	ft_parse_players(argv);
	return (EXIT_SUCCESS);
}
