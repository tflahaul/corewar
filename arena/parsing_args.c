/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 16:08:30 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <corewar_options.h>
#include <corewar_compiler.h>

static inline int		ft_valid_file_fmt(char const *file)
{
	char				*ptr;

	if (__unlikely((ptr = ft_strrchr(file, '.')) == NULL))
		return (EXIT_ERROR);
	return (ft_strcmp(ptr, FILE_FORMAT));
}

static inline void		ft_scan_warriors_id(void)
{
	int32_t				id;
	t_warrior			*node;

	node = g_arena.warriors;
	while (node != NULL)
	{
		if (node->id == COREWAR_EXEC_MAGIC)
		{
			id = 0;
			while (ft_number_in_list(id) == EXIT_FAILURE)
				++id;
			node->id = id;
		}
		node = node->next;
	}
}

int						ft_parse_args(int argc, char const **argv)
{
	if (__unlikely(argc < 2))
		return (ft_puterror(NULL));
	while (*(++argv) != NULL)
	{
		if (**argv == '-')
			ft_get_options(&argv);
		else if (__likely(ft_valid_file_fmt(*argv) == 0))
		{
			if (ft_parse_warrior(*argv) != EXIT_SUCCESS)
				return (EXIT_FAILURE);
		}
		else
			return (ft_puterror(BADFMT"\n"HELPMSG));
	}
	if (__unlikely(g_arena.warriors == NULL))
		return (ft_puterror(NOCHAMP));
	else if (__unlikely(ft_list_size_warrior() > MAX_PLAYERS))
		return (ft_puterror(MAXCHAMP));
	ft_scan_warriors_id();
	return (EXIT_SUCCESS);
}
