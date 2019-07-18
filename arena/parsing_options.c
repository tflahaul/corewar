/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:19:28 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:24:19 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>
#include <arena_errors.h>
#include <corewar_options.h>
#include <corewar_compiler.h>

static inline char		*ft_option_trim(char const *argument)
{
	char				*ptr;
	register uint16_t	index = 0;

	ptr = (char *)argument;
	while (*ptr == '-' && __likely(++index <= 2))
		++ptr;
	return (ptr);
}

static inline int		ft_long_option_lookup(char const *argument)
{
	int					ret = EXIT_ERROR;
	register uint16_t	index = 0;

	while (options[index++].longname != 0)
		if (ft_strcmp(argument, options[index - 1].longname) == 0)
			ret = index - 1;
	return (ret);
}

static inline int		ft_short_option_lookup(char const *argument)
{
	int					ret = EXIT_ERROR;
	register uint16_t	index = 0;

	if (__unlikely(*(argument + 1)))
		return (EXIT_ERROR);
	while (options[index++].longname != 0)
		if (*argument == options[index - 1].shortname)
			ret = index - 1;
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
	if (options[index].has_arg == required_argument)
		++(*argv);
	(*options[index].funptr)(*argv);
}
