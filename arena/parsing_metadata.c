/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_metadata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:46:39 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 14:12:32 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <op.h>
#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <corewar_compiler.h>

static inline int			ft_read_filetype(int fd)
{
	unsigned int			magic = 0;

	if (__unlikely(read(fd, &magic, sizeof(magic)) < 0))
		return (EXIT_ERROR);
	if (__unlikely(ft_swap_uint32(magic) != COREWAR_EXEC_MAGIC))
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

static inline int			ft_read_program_name(int fd)
{
	unsigned char			buffer[PROG_NAME_LENGTH + 1];

	if (__unlikely(lseek(fd, offsetof(header_t, prog_name), SEEK_SET) < 0))
		return (EXIT_ERROR);
	if (__unlikely(read(fd, buffer, sizeof(((header_t *)0)->prog_name)) < 0))
		return (EXIT_ERROR);
	buffer[PROG_NAME_LENGTH] = 0;
	strcpy(g_arena.warriors->name, (char *)buffer);
	return (EXIT_SUCCESS);
}

static inline int			ft_read_program_size(int fd)
{
	unsigned int			size = 0;

	if (__unlikely(lseek(fd, offsetof(header_t, prog_size), SEEK_SET) < 0))
		return (EXIT_ERROR);
	if (__unlikely(read(fd, &size, sizeof(size)) < 0))
		return (EXIT_ERROR);
	size = ft_swap_uint32(size);
	if (size == 0 || size > CHAMP_MAX_SIZE)
		return (EXIT_ERROR);
	g_arena.warriors->size = size;
	return (EXIT_SUCCESS);
}

static inline int			ft_read_program_comment(int fd)
{
	unsigned char			buffer[COMMENT_LENGTH + 1];

	if (__unlikely(lseek(fd, offsetof(header_t, comment), SEEK_SET) < 0))
		return (EXIT_ERROR);
	if (__unlikely(read(fd, buffer, sizeof(((header_t *)0)->comment)) < 0))
		return (EXIT_ERROR);
	buffer[COMMENT_LENGTH] = 0;
	strcpy(g_arena.warriors->comment, (char *)buffer);
	return (EXIT_SUCCESS);
}

__attribute__((noinline))
int							ft_fetch_and_check_metadata(int fd)
{
	if (__unlikely(ft_read_filetype(fd) < 0))
		return (ft_puterror_and_close_fd(FILERR, fd));
	if (__unlikely(ft_read_program_name(fd) < 0))
		return (ft_puterror_and_close_fd(METAERR, fd));
	if (__unlikely(ft_read_program_size(fd) < 0))
		return (ft_puterror_and_close_fd(CHAMPSIZERR, fd));
	if (__unlikely(ft_read_program_comment(fd) < 0))
		return (ft_puterror_and_close_fd(METAERR, fd));
	return (EXIT_SUCCESS);
}
