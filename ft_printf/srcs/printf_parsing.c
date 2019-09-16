/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:47:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/01/31 17:47:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void			ft_reset_struct_datas(t_format *format)
{
	if (format != NULL)
	{
		format->conv = 0;
		format->padding = 0;
		format->flength = 0;
		format->flags[0] = 0;
		format->flags[1] = 0;
		format->flags[2] = 0;
		format->flags[3] = 0;
		format->flags[4] = 0;
		format->flags[5] = 0;
		format->flags[6] = 0;
		format->precision = 0;
		format->padding_char = ' ';
	}
}

t_funptr		*ft_printf_dispatcher(char flag)
{
	if (flag == 'd' || flag == 'i' || flag == 'D')
		return (&ft_putnbr_printf);
	else if (flag == 's' || flag == 'S')
		return (&ft_putstr_printf);
	else if (flag == 'c')
		return (&ft_putchar_printf);
	else if (flag == 'x' || flag == 'u' || flag == 'X' || flag == 'o')
		return (&ft_putnbr_base_printf);
	else if (flag == 'U' || flag == 'O')
		return (&ft_putnbr_base_printf);
	else if (flag == 'b')
		return (&ft_putbinary_printf);
	else if (flag == 'p')
		return (&ft_putaddress_printf);
	else if (flag == 'f')
		return (&ft_putdouble_printf);
	else if (flag == 'n')
		return (&ft_get_numprinted);
	return (NULL);
}

static short	ft_get_more_format(char const *fmt, t_format *p)
{
	if (*fmt == '0' && ++p->flength)
	{
		p->padding_char = *fmt;
		return (1);
	}
	else if (*fmt == '.' && *(fmt + 1) != '-' && ++p->flength)
	{
		p->precision = ft_atoi_light(fmt + 1) + 1;
		if (*(fmt + 1) >= '0' && *(fmt + 1) <= '9')
		{
			p->flength += ft_unsigned_length(p->precision - 1);
			return ((short)ft_unsigned_length(p->precision - 1) + 1);
		}
		return (1);
	}
	return (0);
}

void			ft_get_format(char const *fmt, t_format *p)
{
	short		ret;
	int			index;
	char		*conversions;

	conversions = CONVS;
	if ((index = ft_strchr_index(*fmt, conversions)) && ++p->flength)
		p->conv = conversions[index - 1];
	else if (*fmt > '0' && *fmt <= '9')
	{
		p->padding = ft_unsigned_atoi(fmt);
		p->flength += ft_unsigned_length(p->padding);
		return (ft_get_format(fmt + ft_unsigned_length(p->padding), p));
	}
	else if ((index = ft_strchr_index(*fmt, FLAGS)) && ++p->flength)
	{
		++p->flags[index - 1];
		return (ft_get_format(fmt + 1, p));
	}
	else if (*fmt == '%' && ++p->flength)
		return (ft_putpercent(p));
	else if ((ret = ft_get_more_format(fmt, p)) > 0)
		return (ft_get_format(fmt + ret, p));
	else if (*fmt && ++p->flength)
		ft_write_char_pf(p, *fmt);
}
