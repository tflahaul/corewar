/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:28:00 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:01:47 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <libft.h>
#include <arena_errors.h>
#include <arena_process.h>

int					ft_puterror(char const *string)
{
	if (string != NULL)
		dprintf(STDERR_FILENO, "corewar: %s\n", string);
	else
		write(STDERR_FILENO, HELPMSG"\n", ft_strlen(HELPMSG) + 1);
	return (EXIT_ERROR);
}

int					ft_puterror_illegal_option(char const *string)
{
	dprintf(STDERR_FILENO, "corewar: Illegal option -- %s\n", string);
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
	if (__builtin_expect((close(fd) < 0), 0))
		ft_puterror(strerror(errno));
	return (ft_puterror(string));
}
