/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:47:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/01/31 17:47:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static void				ft_formatted_bin(t_format *p, t_uint nb, t_ulli i)
{
	while (i >>= 1)
		i & nb ? ft_write_char_pf(p, '1') : ft_write_char_pf(p, '0');
	if (!p->flags[3] && p->padding > 8 && p->padding <= INT_MAX)
		while (p->padding-- > 8)
			ft_write_char_pf(p, ' ');
}

void					ft_putbinary_printf(t_format *p, va_list *argument)
{
	t_ulli				i;
	t_uint				nb;

	i = (p->flags[3] ? 4294967296 : 256);
	nb = va_arg(*argument, t_uint);
	if (p->flags[1])
		return (ft_formatted_bin(p, nb, i));
	if (!p->flags[3] && p->padding > 8 && p->padding <= INT_MAX)
		while (p->padding-- > 8)
			ft_write_char_pf(p, ' ');
	while (i >>= 1)
		i & nb ? ft_write_char_pf(p, '1') : ft_write_char_pf(p, '0');
}
