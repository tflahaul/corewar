/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_warrior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:46:39 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:23:34 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <corewar_compiler.h>
#include <arena_errors.h>
#include <arena.h>
#include <libft.h>

static inline void			ft_store_warrior_id(void)
{
	g_arena.warriors->id = COREWAR_EXEC_MAGIC;
	if (HAS_NUMBER(g_arena.options))
	{
		if (__unlikely(ft_number_in_list(g_arena.value) == EXIT_FAILURE))
		{
			ft_puterror(NUMERR);
			exit(EXIT_FAILURE);
		}
		g_arena.warriors->id = g_arena.value;
		UNSET_OPTION_N(g_arena.options);
	}
}

static inline int			ft_store_warrior(int fd)
{
	ssize_t					bytes;
	uint8_t					buffer[CHAMP_MAX_SIZE];

	if (__unlikely(lseek(fd, sizeof(t_header), SEEK_SET) < 0))
		return (ft_puterror(strerror(errno)));
	if (__unlikely((bytes = read(fd, buffer, CHAMP_MAX_SIZE)) < 0))
		return (ft_puterror(strerror(errno)));
	ft_memcpy(g_arena.warriors->program, buffer, bytes);
	ft_store_warrior_id();
	return (EXIT_SUCCESS);
}

int							ft_parse_warrior(char const *file)
{
	int						fd;

	if (__unlikely((fd = open(file, O_RDONLY)) < 0))
		return (ft_puterror(strerror(errno)));
	if (__unlikely(ft_malloc_new_warrior() != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	if (__unlikely(ft_fetch_and_check_metadata(fd) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	if (__unlikely(ft_store_warrior(fd) < 0))
		return (EXIT_FAILURE);
	if (__unlikely(close(fd) < 0))
		return (ft_puterror(strerror(errno)));
	return (EXIT_SUCCESS);
}
