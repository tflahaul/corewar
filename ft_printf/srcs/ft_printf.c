/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:51:11 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/07 15:41:27 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	detect_escape_char(const char *format, t_printf *data, va_list *ap)
{
	int			i;
	int			ret;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_add_char_to_buff(data, format[i++]);
		else
		{
			i++;
			if ((ret = start_fullish_attr(data, (char*)format + i, ap))
				!= ERROR)
				i += ret;
			else
				return ;
		}
	}
	if (data->actual != 0)
		ft_putbuffer(data);
}

int			ft_printf(const char *format, ...)
{
	t_printf	data;
	int			ret;
	va_list		ap;

	if (!format)
		return (ERROR);
	ft_memset(&data, 0, sizeof(t_printf));
	va_start(ap, format);
	detect_escape_char(format, &data, &ap);
	ret = data.ret;
	va_end(ap);
	return (ret);
}
