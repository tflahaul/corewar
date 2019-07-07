/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/07 16:52:32 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "arena.h"
#include "arena_errors.h"
#include "libft.h"

#define __unlikely(x)	__builtin_expect(!!(x), 0)
#define __likely(x)		__builtin_expect(!!(x), 1)

static inline int		ft_valid_file_fmt(char const *file)
{
	char				*ptr;

	if (__unlikely((ptr = strrchr(file, '.')) == NULL))
		return (EXIT_ERROR);
	return (strcmp(ptr, FILE_FORMAT));
}

static int32_t			ft_atoi32(char const *str)
{
	int64_t				nb = 0;

	while (*str == ' ')
		str++;
	if (__unlikely(*str == 0 || ISDIGIT(*str) == 0))
		return (EXIT_ERROR);
	while (ISDIGIT(*str))
	{
		nb = nb * 10 + *str++ - '0';
		if (__unlikely(nb > INT32_MAX))
			return (EXIT_ERROR);
	}
	return (__unlikely(*str) ? EXIT_ERROR : (int32_t)nb);
}

static int				ft_parse_options(char const **av, uint16_t index)
{
	if (strcmp((av[index] + sizeof(char)), "dump") == 0)
	{
		if (__likely(av[++index] != NULL))
			if ((g_arena.dump_cycles = ft_atoi32(av[index])) <= 0)
				return (ft_puterror(BADDUMP));
	}
	else
		return (printf("corewar: Illegal option -- %s\n", av[index] + 1));
	return (EXIT_SUCCESS);
}

static int				ft_parse_args(int argc, char const **argv)
{
	register uint16_t	index = 0;

	while (++index < (uint16_t)argc)
	{
		if (*argv[index] == '-')
		{
			if (ft_parse_options(argv, index++) != EXIT_SUCCESS)
				return (EXIT_ERROR);
		}
		else if (__likely(ft_valid_file_fmt(argv[index]) == 0))
			ft_parse_player(argv[index]);
		else
			return (ft_puterror(BADFMT));
	}
	return (EXIT_SUCCESS);
}

int						main(int argc, char const **argv)
{
	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
