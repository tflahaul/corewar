/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:28:00 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/11 12:55:32 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

#include <libft.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

int					ft_close_fd_on_error(int fd)
{
	close(fd);
	return (EXIT_ERROR);
}

int					ft_puterror(char const *string)
{
	if (string != NULL)
		ft_dprintf(STDERR_FILENO, "corewar: %s\n", string);
	else
		write(STDERR_FILENO, HELPMSG"\n", ft_strlen(HELPMSG) + 1);
	return (EXIT_ERROR);
}

int					ft_puterror_illegal_option(char const *string)
{
	ft_dprintf(STDERR_FILENO, "corewar: Illegal option -- '%s'\n", string);
	return (ft_puterror(NULL));
}

int					ft_puterror_memalloc_failure(t_listhead *head)
{
	ft_puterror(ALLOCFAIL);
	ft_list_delete(head, &ft_get_process);
	return (EXIT_ERROR);
}

int					ft_puterror_and_close_fd(char const *string, int fd)
{
	if (__unlikely((close(fd) < 0)))
		ft_puterror(strerror(errno));
	return (ft_puterror(string));
}
