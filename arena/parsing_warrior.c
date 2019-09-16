/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_warrior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:46:39 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/27 16:24:05 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <corewar_compiler.h>
#include <arena_errors.h>
#include <arena.h>

inline void					ft_scan_warriors_id(void)
{
	int32_t					id;
	t_warrior				*node;

	node = g_arena.warriors;
	while (node != NULL)
	{
		if (node->id == COREWAR_EXEC_MAGIC)
		{
			id = 1;
			while (ft_number_in_list(id) == EXIT_FAILURE)
				++id;
			node->id = id;
		}
		node = node->next;
	}
}

static inline int			ft_store_warrior_id(void)
{
	g_arena.warriors->id = COREWAR_EXEC_MAGIC;
	if (HAS_NUMBER(g_arena.options))
	{
		if (UNLIKELY(ft_number_in_list(g_arena.value) == EXIT_FAILURE))
			return (ft_puterror(NUMERR));
		g_arena.warriors->id = g_arena.value;
		UNSET_OPTION_N(g_arena.options);
	}
	return (EXIT_SUCCESS);
}

static inline int			ft_store_warrior(int fd)
{
	ssize_t					bytes;
	uint8_t					buffer[CHAMP_MAX_SIZE];

	if (UNLIKELY(lseek(fd, sizeof(t_header), SEEK_SET) < 0))
		return (ft_puterror(strerror(errno)));
	if (UNLIKELY((bytes = read(fd, buffer, CHAMP_MAX_SIZE)) < 0))
		return (ft_puterror(strerror(errno)));
	ft_memcpy(g_arena.warriors->program, buffer, bytes);
	if (UNLIKELY(ft_store_warrior_id() < 0))
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

int							ft_parse_warrior(char const *file)
{
	int						fd;

	if (UNLIKELY(g_arena.size >= MAX_PLAYERS))
		return (ft_puterror(MAXCHAMP));
	if (UNLIKELY((fd = open(file, O_RDONLY)) < 0))
		return (ft_puterror(strerror(errno)));
	if (UNLIKELY(ft_malloc_new_warrior() != EXIT_SUCCESS))
		return (ft_close_fd_on_error(fd));
	if (UNLIKELY(ft_fetch_and_check_metadata(fd) != EXIT_SUCCESS))
		return (ft_close_fd_on_error(fd));
	if (UNLIKELY(ft_store_warrior(fd) < 0))
		return (ft_close_fd_on_error(fd));
	if (UNLIKELY(close(fd) < 0))
		return (ft_puterror(strerror(errno)));
	return (EXIT_SUCCESS);
}
