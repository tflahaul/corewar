/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/27 16:25:02 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
			return (ft_puterror(FILERR"\n"HELPMSG));
	}
	if (__unlikely(g_arena.size == 0))
		return (ft_puterror(NOCHAMP"\n"HELPMSG));
	ft_scan_warriors_id();
	return (EXIT_SUCCESS);
}
