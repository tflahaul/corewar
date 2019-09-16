/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:47:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/01/31 17:47:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static void			ft_putstr_right_pf(t_format *p, wchar_t *str, size_t len)
{
	size_t			i;

	i = 0;
	if (p->precision && (p->precision - 1 <= len))
	{
		ft_write_wstr_pf(p, str, p->precision - 1);
		if (p->padding > p->precision - 1)
			while (++i <= p->padding - (p->precision - 1))
				ft_write_char_pf(p, ' ');
	}
	else if (p->padding > len && p->padding < INT_MAX)
	{
		ft_write_wstr_pf(p, str, len);
		while (++i <= p->padding - len)
			ft_write_char_pf(p, ' ');
	}
	else
		ft_write_wstr_pf(p, str, len);
}

void				ft_putstr_printf(t_format *p, va_list *argument)
{
	wchar_t			*str;
	size_t			length;

	if (!(str = va_arg(*argument, wchar_t *)))
		str = (wchar_t *)"(null)";
	length = ft_strlen((char *)str);
	if (p->flags[1])
		ft_putstr_right_pf(p, str, length);
	else if (p->precision && (p->precision - 1 <= length))
	{
		while (p->padding && (p->padding-- - (p->precision - 1) > 0))
			ft_write_char_pf(p, p->padding_char);
		if (p->precision != 1)
			ft_write_wstr_pf(p, str, p->precision - 1);
	}
	else
	{
		if (p->padding && p->padding <= INT_MAX)
			while ((p->padding-- - length) > 0 && p->padding >= length)
				ft_write_char_pf(p, p->padding_char);
		ft_write_wstr_pf(p, str, length);
	}
}

void				ft_putchar_printf(t_format *p, va_list *argument)
{
	t_uint			i;
	unsigned char	c;

	i = 0;
	c = va_arg(*argument, int);
	if (p->flags[1])
	{
		ft_write_char_pf(p, c);
		if (p->padding && p->padding <= INT_MAX)
			while (++i < p->padding)
				ft_write_char_pf(p, ' ');
	}
	else
	{
		if (p->padding && p->padding <= INT_MAX)
			while (++i < p->padding)
				ft_write_char_pf(p, p->padding_char);
		ft_write_char_pf(p, c);
	}
}
