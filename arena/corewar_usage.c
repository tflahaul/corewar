/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:28:00 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/07 16:53:15 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "../arena_errors.h"

int						ft_print_usage(void)
{
	int					fd;
	int					bytes;
	char				buffer[BUFF_SIZE + 1];

	if ((fd = open("help.txt", O_RDONLY)) < 0)
		return (ft_puterror(strerror(errno)));
	while ((bytes = read(fd, buffer, BUFF_SIZE)) > 0)
		write(STDERR_FILENO, buffer, bytes);
	return (EXIT_ERROR);
}
