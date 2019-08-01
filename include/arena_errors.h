/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:28:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:09:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_ERRORS_H
# define ARENA_ERRORS_H

# include <errno.h>

# include "list.h"

# define EXIT_ERROR			-1
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS		0
# endif
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE		1
# endif
# define STDERR_FILENO		2

# define FILERR				"Not a valid corewar executable"
# define ALLOCFAIL			"Memory allocation failure"

# define BADOPTION			"Illegal option -- "
# define BADOPT				"Invalid option value"
# define NULLOPT			"Couldn't find option value"

# define METAERR			"Error while reading metadata"
# define NUMERR				"Two warriors have the same id"
# define NOCHAMP			"No warrior was loaded in the arena"
# define MAXCHAMP			"Trying to load more than 4 warriors in the arena"
# define CHAMPSIZERR		"Bad warrior size (either zero or too large)"

# define HELPMSG			"Try 'corewar --help' for more information"

int							ft_puterror(char const *str);
int							ft_puterror_illegal_option(char const *str);
int							ft_puterror_memalloc_failure(t_listhead *head);
int							ft_puterror_and_close_fd(char const *str, int fd);

#endif /* ARENA_ERRORS_H */
