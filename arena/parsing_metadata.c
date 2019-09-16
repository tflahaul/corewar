/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_metadata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:46:39 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/09 12:14:26 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <arena.h>
#include <arena_errors.h>
#include <corewar_compiler.h>

static inline int			ft_read_filetype(uint8_t *mdata)
{
	if (UNLIKELY(ft_endian_swap(*((uint32_t *)mdata)) != COREWAR_EXEC_MAGIC))
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

static inline int			ft_read_program_size(uint8_t *mdata)
{
	g_arena.warriors->size = ft_endian_swap(*((uint32_t *)mdata));
	if (!(g_arena.warriors->size) || g_arena.warriors->size > CHAMP_MAX_SIZE)
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

static inline void			ft_read_program_name(uint8_t *mdata)
{
	ft_memcpy(g_arena.warriors->name, mdata, ft_strlen((char *)mdata));
}

static inline void			ft_read_program_comment(uint8_t *mdata)
{
	ft_memcpy(g_arena.warriors->comment, mdata, ft_strlen((char *)mdata));
}

int							ft_fetch_and_check_metadata(int fd)
{
	uint8_t					metadata[sizeof(t_header)];

	if (UNLIKELY(read(fd, metadata, sizeof(t_header)) < 0))
		return (ft_close_fd_on_error(fd));
	if (UNLIKELY(ft_read_filetype(metadata) < 0))
		return (ft_puterror_and_close_fd(FILERR, fd));
	ft_read_program_name(metadata + OFFSETOF(t_header, prog_name));
	if (ft_read_program_size(metadata + OFFSETOF(t_header, prog_size)) < 0)
		return (ft_puterror_and_close_fd(CHAMPSIZERR, fd));
	ft_read_program_comment(metadata + OFFSETOF(t_header, comment));
	return (EXIT_SUCCESS);
}
