/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:46:39 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/08 18:56:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "arena_errors.h"
#include "arena.h"
#include "libft.h"
#include "op.h"

#define __unlikely(x)		__builtin_expect(!!(x), 0)
#define __likely(x)			__builtin_expect(!!(x), 1)

#define METATYPE(member)	typeof(((header_t *)42)->member)
#define METASIZE(member)	sizeof(((header_t *)42)->member)

static inline uint32_t		ft_swap_uint32(uint32_t nb)
{
	return (((nb & 0xff000000) >> 24) | ((nb & 0x00ff0000) >> 8) |
			((nb & 0x0000ff00) << 8) | ((nb & 0x000000ff) << 24));
}

static inline int			ft_read_filetype(int fd)
{
	METATYPE(magic)			magic = 0;

	if (__unlikely(read(fd, &magic, sizeof(magic)) < 0))
		return (EXIT_ERROR);
	if (__unlikely(ft_swap_uint32(magic) != COREWAR_EXEC_MAGIC))
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

static inline int			ft_read_program_name(int fd)
{
	unsigned char			buffer[PROG_NAME_LENGTH + 1];

	if (__unlikely(read(fd, buffer, PROG_NAME_LENGTH + 1) < 0))
		return (EXIT_ERROR);
	buffer[PROG_NAME_LENGTH] = 0;
// Load buffer into name field of t_player struct
	return (EXIT_SUCCESS);
}

__deprecated_msg("size toujours == 0")
static inline int			ft_read_program_size(int fd)
{
	METATYPE(prog_size)		size = 0;

	if (__unlikely(read(fd, &size, sizeof(size)) < 0))
		return (EXIT_ERROR);
	printf("size = %#x\n", ft_swap_uint32(size));
	if (__unlikely(!size || ft_swap_uint32(size) > CHAMP_MAX_SIZE))
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

__attribute__((noinline))
int							ft_save_players_program(char const *file)
{
	register int			fd;

	if (__unlikely((fd = open(file, O_RDONLY)) < 0))
		return (ft_puterror(strerror(errno)));
	if (__unlikely(ft_read_filetype(fd) < 0))
		return (ft_puterror_and_close_fd(FILERR, fd));
	if (__unlikely(ft_read_program_name(fd) < 0))
		return (ft_puterror_and_close_fd(METAERR, fd));
	if (__unlikely(ft_read_program_size(fd) < 0))
		return (ft_puterror_and_close_fd(CHAMPSIZERR, fd));
	if (__unlikely(close(fd) < 0))
		return (ft_puterror(strerror(errno)));
	return (EXIT_SUCCESS);
}

int							main(__unused int argc, char const **argv)
{
	ft_save_players_program(argv[1]);
	return (0);
}
