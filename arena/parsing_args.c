/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 14:46:27 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <corewar_compiler.h>

static inline int		ft_valid_file_fmt(char const *file)
{
	char				*ptr;

	if (__unlikely((ptr = strrchr(file, '.')) == NULL))
		return (EXIT_ERROR);
	return (strcmp(ptr, FILE_FORMAT));
}

static int				ft_parse_options(char const **av, uint16_t index)
{
	if (strcmp((av[index] + 1), "dump") == 0)
	{
		if (__likely(av[++index] != NULL))
		{
			if ((g_arena.dump_cycles = ft_atoi_max_int32(av[index])) <= 0)
				return (ft_puterror(BADOPT));
		}
		else
			return (ft_puterror(NULLOPT));
	}
	else if (strcmp((av[index] + 1), "n") == 0)
	{
		if (__likely(av[++index] != NULL))
		{
			if ((g_arena.option = ft_atoi_max_int32(av[index])) < 0)
				return (ft_puterror(BADOPT));
		}
		else
			return (ft_puterror(NULLOPT));
	}
	else if (strcmp((av[index] + 1), "-help") == 0)
		return (ft_print_usage());
	else
		return (printf("corewar: "BADOPTION"%s\n"HELPMSG"\n", av[index] + 1));
	return (EXIT_SUCCESS);
}

int						ft_parse_args(int argc, char const **argv)
{
	register uint16_t	index = 0;

	if (__unlikely(argc < 2))
		return (ft_puterror(NULL));
	while (++index < (uint16_t)argc)
	{
		if (*argv[index] == '-')
		{
			if (ft_parse_options(argv, index++) != EXIT_SUCCESS)
				return (EXIT_ERROR);
		}
		else if (__likely(ft_valid_file_fmt(argv[index]) == 0))
		{
			if (ft_parse_warrior(argv[index]) != EXIT_SUCCESS)
				return (EXIT_ERROR);
		}
		else
			return (ft_puterror(BADFMT"\n"HELPMSG));
	}
	if (__unlikely(g_arena.warriors == NULL))
		return (ft_puterror(NOCHAMP));
	return (EXIT_SUCCESS);
}
