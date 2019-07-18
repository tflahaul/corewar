/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:54:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:06:44 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <corewar_options.h>
#include <corewar_compiler.h>

void					ft_print_help(char const **argv)
{
	int					fd;
	int					bytes;
	char				buffer[BUFF_SIZE + 1];

	(void)argv;
	if ((fd = open("help.txt", O_RDONLY)) < 0)
	{
		ft_puterror(strerror(errno));
		exit(EXIT_ERROR);
	}
	while ((bytes = read(fd, buffer, BUFF_SIZE)) > 0)
		write(STDERR_FILENO, buffer, bytes);
	if (close(fd) < 0)
	{
		ft_puterror(strerror(errno));
		exit(EXIT_ERROR);
	}
	exit(EXIT_SUCCESS);
}

void					ft_set_visualize(char const **argv)
{
	(void)argv;
	g_arena.options |= OPTION_V;
}

void					ft_get_dump(char const **argv)
{
	if (__unlikely(*argv == NULL))
	{
		ft_puterror(NULLOPT);
		exit(EXIT_FAILURE);
	}
	if ((g_arena.dump_cycles = ft_atoi32_max(*argv)) == EXIT_ERROR)
	{
		ft_puterror(BADOPT);
		exit(EXIT_FAILURE);
	}
}

void					ft_get_numb(char const **argv)
{
	if (__unlikely(*argv == NULL))
	{
		ft_puterror(NULLOPT);
		exit(EXIT_FAILURE);
	}
	g_arena.options |= OPTION_N;
	if ((g_arena.value = ft_atoi32_max(*argv)) == EXIT_ERROR)
	{
		ft_puterror(BADOPT);
		exit(EXIT_FAILURE);
	}
}
