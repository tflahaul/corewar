/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_xu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:47:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/07 11:25:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static void		ft_formatted_right_hex(t_format *p, char const *str, size_t sz)
{
	int			len;
	int			new;
	int			last;
	t_uint		index;

	len = 0;
	index = 0;
	last = p->printed;
	if (p->flags[0] && p->conv != 'u')
		len = 2;
	if (p->precision && p->precision - 1 > sz - len)
	{
		if (p->flags[0] && len && ft_strcmp(str, "0"))
			if (ft_write_str(p, str, len) && (str += len))
				sz -= len;
		while (index++ < p->precision - sz - 1)
			ft_write_char_pf(p, '0');
	}
	if (!(!ft_strcmp(str, "0") && p->precision == 1))
		ft_write_str(p, str, sz);
	new = p->printed;
	if (p->padding > (size_t)p->printed - last && p->padding <= INT_MAX)
		while (p->padding-- > (size_t)(new - last))
			ft_write_char_pf(p, ' ');
}

static void		ft_formatted_prec_hex(t_format *p, char const *str, size_t sz)
{
	t_uint		flag;
	t_uint		temp;
	t_uint		padding;
	t_uint		precision;

	flag = 0;
	padding = p->padding;
	precision = p->precision;
	temp = (p->precision - 1 > sz ? (sz + p->precision - sz - 1) : sz);
	if (p->flags[0] && ft_strcmp(str, "0"))
		flag = 2;
	if (p->padding > 0 && p->padding <= INT_MAX)
		while (p->padding-- > temp + flag)
			ft_write_char_pf(p, ' ');
	if (p->flags[0] && ft_strcmp(str, "0"))
		if (ft_write_str(p, str, 2) && (str += 2))
			sz = sz > 1 ? sz - 2 : 0;
	while (--p->precision > sz)
		ft_write_char_pf(p, '0');
	if (!(precision == 1 && !ft_strcmp(str, "0")))
		ft_write_str(p, str, sz);
	else if (padding)
		ft_write_char_pf(p, ' ');
}

static void		ft_formatted_hex(t_format *p, char const *str, size_t sz)
{
	if (p->flags[1])
		return (ft_formatted_right_hex(p, str, sz));
	else if (p->precision)
		return (ft_formatted_prec_hex(p, str, sz));
	if (p->flags[0] && p->padding_char == '0' && ft_write_str(p, str, 2))
		str += 2;
	if (p->padding > sz && p->padding <= INT_MAX)
		while (p->padding-- > sz)
			ft_write_char_pf(p, p->padding_char);
	ft_write_str(p, str, ft_strlen(str));
}

void			ft_putnbr_hexadecimal(t_format *p, t_ulli nb)
{
	int			base;
	char		*str;

	base = 10;
	if (p->conv != 'u' && p->conv != 'U')
		base = 16;
	if (!nb)
		ft_formatted_hex(p, (str = ft_strndup("0", 1)), 1);
	else if ((str = ft_itoa_base(nb, base)))
	{
		if (p->conv == 'x')
			ft_lowerstr(&str);
		if (p->flags[0])
			if (!(str = ft_strjoinfree(ft_handle_prefix(p->conv), str, 'B')))
				return ;
		ft_formatted_hex(p, str, ft_strlen(str));
	}
	if (str != NULL)
		free((void *)str);
}

void			ft_putnbr_base(t_format *p, t_ulli nb)
{
	if (p->conv == 'o' || p->conv == 'O')
		ft_putnbr_octal(p, nb);
	else
		ft_putnbr_hexadecimal(p, nb);
}
