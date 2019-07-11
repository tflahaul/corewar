/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:28:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 14:39:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_ERRORS_H
# define ARENA_ERRORS_H

# include <errno.h>

# define EXIT_ERROR			-1

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS		0
# endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE		1
# endif

# define STDERR_FILENO		2

# define BUFF_SIZE			512

# define BADOP				"Unknown instruction"

# define FILERR				"Unsupported file type"
# define BADFMT				"Unknown file extension"

# define BADOPTION			"Illegal option -- "
# define BADOPT				"Invalid option value"
# define NULLOPT			"Couldn't find option value"

# define METAERR			"Error while reading metadata"
# define NOCHAMP			"No warrior was loaded in the arena"
# define CHAMPSIZERR		"Bad champion size (either zero or too large)"

# define HELPMSG			"Try 'corewar --help' for more information"

int							ft_print_usage(void);
int							ft_puterror(char const *str);
int							ft_puterror_and_close_fd(char const *str, int fd);

#endif /* ARENA_ERRORS_H */
