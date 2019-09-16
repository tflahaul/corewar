/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_np.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:47:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/01/31 17:47:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void				ft_putpercent(t_format *p)
{
	if (p->padding && !p->flags[1] && p->padding <= INT_MAX)
	{
		while (--p->padding)
			ft_write_char_pf(p, p->padding_char);
		ft_write_char_pf(p, '%');
	}
	else if (p->padding && p->flags[1])
	{
		ft_write_char_pf(p, '%');
		while (--p->padding)
			ft_write_char_pf(p, ' ');
	}
	else
		ft_write_char_pf(p, '%');
}

void				ft_get_numprinted(t_format *p, va_list *argument)
{
	long long		*ptr;

	if (!(ptr = va_arg(*argument, long long int *)))
		return ;
	if (p->flags[4] == 1)
		*ptr = (short int)p->printed;
	else if (p->flags[4] > 1)
		*ptr = (char)p->printed;
	else if (p->flags[3] == 1)
		*ptr = (long int)p->printed;
	else if (p->flags[3] > 1)
		*ptr = p->printed;
	else
		*ptr = (int)p->printed;
}

void				ft_putaddr_right_pf(t_format *p, char const *address)
{
	size_t			length;

	length = ft_strlen(address);
	ft_write_str(p, (char *)address, length);
	if (p->padding && p->padding <= INT_MAX)
		while (p->padding-- > length)
			ft_write_char_pf(p, ' ');
}

void				ft_formatted_addr(t_format *p, char const *address)
{
	size_t			length;

	length = ft_strlen(address);
	if (p->flags[1])
		return (ft_putaddr_right_pf(p, address));
	if (p->padding_char == '0' && p->precision != 1)
	{
		ft_write_str(p, (char *)address, 2);
		address += 2;
	}
	if (p->padding && p->precision == 1)
	{
		while (p->padding-- > 2)
			ft_write_char_pf(p, ' ');
		ft_write_str(p, (char *)address, 2);
	}
	else if (p->padding && p->padding <= INT_MAX)
		while (p->padding-- > length)
			ft_write_char_pf(p, p->padding_char);
	if (p->precision != 1)
		ft_write_str(p, (char *)address, 0);
}

void				ft_putaddress_printf(t_format *p, va_list *argument)
{
	char			*str;
	int				length;
	t_ulli			address;
	char const		*base;

	address = (t_ulli)va_arg(*argument, void *);
	base = "0123456789abcdef";
	length = ft_unsigned_length(address);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return ;
	str[length] = 0;
	if (!address)
		str[--length] = '0';
	while (address)
	{
		str[--length] = base[address % 16];
		address = address / 16;
	}
	str[--length] = 'x';
	str[--length] = '0';
	ft_formatted_addr(p, str + length);
	free((void *)str);
}
