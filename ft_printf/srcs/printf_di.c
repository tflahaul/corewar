/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:47:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/01/31 17:47:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static void		ft_formated_right_int(t_format *p, char const *str)
{
	char		ng;
	size_t		length;
	t_uint		nblength;

	ng = 0;
	length = ft_strlen(str);
	nblength = ft_integer_length(ft_atoi_light(str));
	if (p->flags[2] && *str != '-' && ft_write_char_pf(p, '+'))
		if (p->padding && !(p->flags[2] = 0))
			--p->padding;
	if (p->precision && p->precision - 1 > nblength)
	{
		if (*str == '-' && ft_write_char_pf(p, *str) && str++ && (ng = 1))
			length -= (length ? 1 : 0);
		else if (p->flags[2])
			ft_write_char_pf(p, '+');
		while (--p->precision > nblength && ft_write_char_pf(p, '0'))
			p->padding -= (p->padding ? 1 : 0);
	}
	ft_write_str(p, str, length);
	if (p->padding > length && p->padding <= INT_MAX)
		while (p->padding-- > length + ng)
			ft_write_char_pf(p, ' ');
}

static void		ft_fmt_precision_int(t_format *p, char *s, t_uint pr, t_uint pd)
{
	int			nb;
	t_uint		ptemp;

	ptemp = 0;
	nb = ABS(ft_atoi_light(s));
	if (p->flags[6] && !p->flags[2] && *s != '-' && ft_write_char_pf(p, ' '))
		p->padding -= (p->padding ? 1 : 0);
	if (p->precision - 1 > ft_integer_length(nb))
		ptemp = p->precision - ft_integer_length(nb) - 1;
	if (p->flags[2] && *s != '-')
		if ((p->padding <= ++ptemp + ft_strlen(s)) && !(p->flags[2] = 0))
			ft_write_char_pf(p, '+');
	if (p->padding && p->padding <= INT_MAX)
		while (p->padding && p->padding-- > ptemp + ft_strlen(s))
			ft_write_char_pf(p, ' ');
	if (p->flags[2] && *s != '-')
		ft_write_char_pf(p, '+');
	else if (*s == '-')
		ft_write_char_pf(p, *s++);
	while (--p->precision > ft_integer_length(nb))
		ft_write_char_pf(p, '0');
	if (!(!ft_strcmp(s, "0") && pr == 1))
		ft_write_str(p, s, ft_strlen(s));
	else if (pd)
		ft_write_char_pf(p, ' ');
}

static void		ft_formatted_int(t_format *p, char *s, size_t u)
{
	char		ng;

	ng = 0;
	if (p->precision)
		return (ft_fmt_precision_int(p, s, p->precision, p->padding));
	if (p->flags[6] && !p->flags[2] && *s != '-' && ft_write_char_pf(p, ' '))
		p->padding -= (p->padding ? 1 : 0);
	if (p->flags[2] && *s != '-' && ++u && (ng = 1))
		if ((p->padding <= u || p->padding_char == '0') && !(p->flags[2] = 0))
			ft_write_char_pf(p, '+');
	if (p->padding && p->padding <= INT_MAX)
	{
		if (*s == '-' && p->padding_char == '0' && !(p->flags[2] = 0))
			if (ft_write_str(p, (char *)s, 1) && (ng = 1))
				s++;
		while (p->padding-- > u)
			ft_write_char_pf(p, p->padding_char);
	}
	if (p->flags[2] && (*s != '-'))
		ft_write_char_pf(p, '+');
	ft_write_str(p, s, u - ng);
}

static void		ft_putnbr_integer(t_format *p, long long num)
{
	char		*str;
	t_ulli		value;
	t_uint		length;

	length = ft_integer_length(num) + (num < 0 ? 1 : 0);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return ;
	str[length] = 0;
	if (num <= 0)
		str[0] = num < 0 ? '-' : '0';
	value = ABS(num);
	while (value && length)
	{
		str[--length] = value % 10 + 48;
		value = value / 10;
	}
	if (p->flags[1] && !(p->precision == 1 && !ft_strcmp(str, "0")))
		ft_formated_right_int(p, str);
	else
		ft_formatted_int(p, str, ft_integer_length(num) + 1);
	free((void *)str);
}

void			ft_putnbr_printf(t_format *p, va_list *argument)
{
	long long	nb;

	nb = va_arg(*argument, long long);
	if (p->conv == 'D')
		ft_putnbr_integer(p, (long)nb);
	if (!p->flags[3] && !p->flags[4])
		ft_putnbr_integer(p, (int)nb);
	else if (p->flags[3] == 1 && !p->flags[4])
		ft_putnbr_integer(p, (long)nb);
	else if (p->flags[3] > 1 && !p->flags[4])
		ft_putnbr_integer(p, nb);
	else if (p->flags[4] == 1 && !p->flags[3])
		ft_putnbr_integer(p, (short)nb);
	else if (p->flags[4] > 1 && !p->flags[3])
		ft_putnbr_integer(p, (char)nb);
	else
		ft_putnbr_integer(p, (short)nb);
}
