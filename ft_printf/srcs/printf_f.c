/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:56:27 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/06 10:56:27 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static void		ft_formatted_right_fp(t_format *p, char const *s, size_t len)
{
	ft_write_str(p, s, len);
	if (p->padding > len && p->padding <= INT_MAX)
		while (p->padding-- > len)
			ft_write_char_pf(p, ' ');
}

static void		ft_formatted_fp(t_format *p, char *str, size_t len)
{
	if (!str)
		return ;
	if (p->flags[2] && *str != '-' && ft_write_char_pf(p, '+'))
		p->padding -= (p->padding ? 1 : 0);
	else if (p->flags[6] && *str != '-' && ft_write_char_pf(p, ' '))
		if (p->padding)
			--p->padding;
	if (p->flags[1])
		return (ft_formatted_right_fp(p, str, len));
	if (*str == '-')
		ft_write_char_pf(p, *str++);
	if (p->padding > len && p->padding <= INT_MAX)
		while (p->padding-- > len)
			ft_write_char_pf(p, p->padding_char);
	ft_write_str(p, str, len);
}

static void		ft_double_to_str(t_format *p, long double nb, int fp, char *s)
{
	long long	itemp;
	long long	ipart;
	long long	deci;

	deci = 0;
	ipart = (long long)nb;
	itemp = (long long)(nb * 10);
	itemp = (itemp % 10 > 4 ? (itemp / 10) + 1 : itemp / 10);
	if (!nb)
	{
		s[0] = '0';
		s[1] = '.';
		ft_memset(s + 2, '0', fp - 1);
	}
	else
	{
		if (p->precision != 1)
		{
			deci = (long long)((nb - (long double)ipart) * ft_power(fp, 10));
			deci = (deci % 10 > 4 ? (deci / 10) + 1 : deci / 10);
		}
		ft_itoa_fp((p->precision == 1 ? itemp : ipart), deci, s);
		if (!deci && p->precision != 1)
			ft_memset(s + ft_strlen(s), '0', fp - 1);
	}
}

static void		ft_putdouble(t_format *p, long double nb)
{
	char		*string;
	size_t		l;
	long long	ipart;
	long double	n;

	n = ABS(nb);
	l = ft_integer_length((long long)n) + (p->precision ? p->precision - 1 : 6);
	if (p->precision == 1 && !p->flags[0])
	{
		ipart = ABS(nb * 10);
		if (ipart % 10 < 5)
			ipart = (ipart % 10 > 4 ? (ipart / 10) + 1 : ipart / 10);
		else if ((ipart = ABS(nb * 100)) < (LLONG_MAX / 10))
			ipart = (ipart % 10 > 5 ? (ipart / 100) + 1 : ipart / 100);
		string = ft_itoa(ipart);
	}
	else if ((string = ft_strnew(l + 1)))
		ft_double_to_str(p, n, l - ft_integer_length(n) + 1, string);
	if (nb < 0)
		string = ft_strjoinfree("-", string, 'R');
	ft_formatted_fp(p, string, ft_strlen(string));
	if (string != NULL)
		free((void *)string);
}

void			ft_putdouble_printf(t_format *p, va_list *argument)
{
	long double	nb;

	if (p->flags[3] == 1 || p->flags[5] == 1)
		nb = va_arg(*argument, long double);
	else
		nb = va_arg(*argument, double);
	ft_putdouble(p, nb);
}
