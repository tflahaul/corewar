/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:40:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/07 11:24:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int						ft_printf(char const *format, ...)
{
	t_format			p;
	t_funptr			*ptr;
	va_list				argument_list;

	if (!format || !(*format))
		return (0);
	p.printed = 0;
	ft_reset_struct_datas(&p);
	va_start(argument_list, format);
	while (*format)
	{
		if (*format++ == '%')
		{
			ft_get_format(format++, &p);
			if ((ptr = ft_printf_dispatcher(p.conv)))
				ptr(&p, &argument_list);
			format += p.flength > 1 ? p.flength - 1 : 0;
			ft_reset_struct_datas(&p);
		}
		else if (*(format - 1))
			ft_write_char_pf(&p, *(format - 1));
	}
	va_end(argument_list);
	return (p.printed);
}
