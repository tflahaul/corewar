/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:19:28 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/08 10:30:22 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>
#include <arena_errors.h>
#include <corewar_options.h>
#include <corewar_compiler.h>

static t_options		g_options[] = {
	{"number", &ft_get_numb, required_argument, 'n'},
	{"help", &ft_print_help, no_argument, 'h'},
	{"dump", &ft_get_dump, required_argument, 'd'},
	{"print", &ft_set_print, no_argument, 'p'},
	{0, 0, 0, 0}
};

static inline char		*ft_option_trim(char const *argument)
{
	char				*ptr;
	register uint16_t	index;

	index = 0;
	ptr = (char *)argument;
	while (*ptr == '-' && __likely(++index <= 2))
		++ptr;
	return (ptr);
}

static inline int		ft_long_option_lookup(char const *argument)
{
	int					ret;
	register uint16_t	index;

	index = 0;
	ret = EXIT_ERROR;
	while (g_options[index++].longname != 0)
		if (ft_strcmp(argument, g_options[index - 1].longname) == 0)
			return (index - 1);
	return (ret);
}

static inline int		ft_short_option_lookup(char const *argument)
{
	int					ret;
	register uint16_t	index;

	index = 0;
	ret = EXIT_ERROR;
	if (__unlikely(*(argument + 1)))
		return (EXIT_ERROR);
	while (g_options[index++].longname != 0)
		if (*argument == g_options[index - 1].shortname)
			return (index - 1);
	return (ret);
}

void					ft_get_options(char const ***argv)
{
	int					index;

	if ((*argv)[0][1] && (*argv)[0][1] == '-')
		index = ft_long_option_lookup(ft_option_trim((*argv)[0]));
	else
		index = ft_short_option_lookup(ft_option_trim((*argv)[0]));
	if (__unlikely(index < 0))
	{
		ft_puterror_illegal_option(ft_option_trim(**argv));
		exit(EXIT_FAILURE);
	}
	if (g_options[index].has_arg == required_argument)
		++(*argv);
	(*g_options[index].funptr)(*argv);
}
