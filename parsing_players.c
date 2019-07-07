/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:46:39 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/07 17:06:30 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "arena.h"
#include "arena_errors.h"
#include "libft.h"

#define __unlikely(x)	__builtin_expect(!!(x), 0)
#define __likely(x)		__builtin_expect(!!(x), 1)

static int				ft_read_metadata(unsigned char *header)
{
	unsigned int		*mask = (unsigned int *)header;

	printf("%x", mask[0]);
	return (EXIT_SUCCESS);
}

int						ft_save_players_program(char const *file)
{
	int					fd;
	unsigned char		prog[CHAMP_MAX_SIZE + sizeof(header_t)];

	__builtin_memset(prog, 0, sizeof(prog));
	if (__unlikely((fd = open(file, O_RDONLY)) < 0))
		return (ft_puterror(strerror(errno)));
	if (__unlikely(read(fd, &prog, sizeof(header_t)) < 0))
		return (ft_puterror_and_close_fd(strerror(errno), fd));
	if (__unlikely(ft_read_metadata(prog) < 0))
		return (ft_puterror_and_close_fd(HEADERR, fd));
	__builtin_memset(prog, 0, sizeof(prog));
	if (__unlikely(read(fd, &prog, CHAMP_MAX_SIZE) <= 0))
		return (ft_puterror_and_close_fd(strerror(errno), fd));
	__builtin_memcpy(g_arena.players.program, &prog, sizeof(prog)); // hot
//	if (__unlikely(read(fd, &prog, sizeof(unsigned char)) != 0))
//		return (ft_puterror_and_close_fd(TOOLARGE, fd));
	if (__unlikely(close(fd) < 0))
		return (ft_puterror(strerror(errno)));
	return (EXIT_SUCCESS);
}

int						main(__unused int argc, char const **argv)
{
	ft_save_players_program(argv[1]);
	return (0);
}
