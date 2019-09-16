/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:45:14 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:45:14 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static void		ft_formatted_right_octal(t_format *p, char const *s, size_t sz)
{
	t_uint		precision;

	precision = p->precision;
	if (p->precision > 1)
	{
		while (--p->precision > sz)
		{
			p->padding -= (p->padding ? 1 : 0);
			ft_write_char_pf(p, '0');
		}
	}
	if (!(precision == 1 && !ft_strcmp(s, "0") && !p->flags[0]))
		ft_write_str(p, s, sz);
	else if (p->padding)
		ft_write_char_pf(p, ' ');
	if (p->padding > 0 && p->padding <= INT_MAX)
		while (p->padding-- > sz)
			ft_write_char_pf(p, ' ');
}

static void		ft_formatted_prec_octal(t_format *p, char const *s, size_t sz)
{
	t_uint		temp;
	t_uint		padding;
	t_uint		precision;

	padding = p->padding;
	precision = p->precision;
	temp = (p->precision - 1 > sz ? p->precision - sz - 1 : 0);
	if (p->padding > sz + temp)
		while (p->padding-- > sz + temp)
			ft_write_char_pf(p, ' ');
	if (p->precision - 1 > sz)
		while (--p->precision > sz)
			ft_write_char_pf(p, '0');
	if (!(precision == 1 && !ft_strcmp(s, "0") && !p->flags[0]))
		ft_write_str(p, s, sz);
	else if (padding)
		ft_write_char_pf(p, ' ');
}

static void		ft_formatted_octal(t_format *p, char const *str)
{
	size_t		length;

	length = ft_strlen(str);
	if (p->flags[1])
		return (ft_formatted_right_octal(p, str, length));
	if (p->precision)
		return (ft_formatted_prec_octal(p, str, length));
	if (p->padding > 0 && p->padding <= INT_MAX)
		while (p->padding-- > length)
			ft_write_char_pf(p, p->padding_char);
	ft_write_str(p, str, length);
}

void			ft_putnbr_octal(t_format *p, t_ulli nb)
{
	char		*string;

	if (!nb)
		ft_formatted_octal(p, (string = ft_strndup("0", 1)));
	else if ((string = ft_itoa_base(nb, 8)))
	{
		if (p->flags[0])
			if (!(string = ft_strjoinfree("0", string, 'R')))
				return ;
		ft_formatted_octal(p, string);
	}
	if (string != NULL)
		free((void *)string);
}

void			ft_putnbr_base_printf(t_format *p, va_list *argument)
{
	t_ulli		nb;

	nb = va_arg(*argument, long long);
	if (p->conv == 'O' || p->conv == 'U')
		ft_putnbr_base(p, (unsigned long)nb);
	else if (!p->flags[3] && !p->flags[4])
		ft_putnbr_base(p, (t_uint)nb);
	else if (p->flags[3] == 1)
		ft_putnbr_base(p, (unsigned long)nb);
	else if (p->flags[3] > 1)
		ft_putnbr_base(p, nb);
	else if (p->flags[4] == 1 && !p->flags[3])
		ft_putnbr_base(p, (unsigned short)nb);
	else if (p->flags[4] > 1 && !p->flags[3])
		ft_putnbr_base(p, (unsigned char)nb);
	else
		ft_putnbr_base(p, (unsigned short)nb);
}
