/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:28:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/08 18:13:27 by thflahau         ###   ########.fr       */
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

# define BADOP				"Unknown instruction"
# define FILERR				"Unsupported file type"
# define BADFMT				"File format is not supported"
# define BADDUMP			"Invalid dump option value"
# define METAERR			"Error while reading metadata"
# define TOOLARGE			"Player is too large"
# define OUTOFRANGE			"Out of range numerical value"
# define CHAMPSIZERR		"Bad champion size (either zero or too large)"

int							ft_puterror(char const *str);
int							ft_puterror_and_close_fd(char const *str, int fd);

#endif /* ARENA_ERRORS_H */
