/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:01:07 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/09 13:01:07 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <libft.h>

void					ft_dprintf(int fd, char const *fmt, ...)
{
	va_list				list;
	char				*string;

	va_start(list, fmt);
	while (*fmt != 0)
	{
		if (*fmt == '%' && *(fmt + 1) == 's')
		{
			if ((string = va_arg(list, char *)) != NULL)
				write(fd, string, ft_strlen(string));
			fmt += 2;
		}
		else
			write(fd, fmt++, 1);
	}
	va_end(list);
}
