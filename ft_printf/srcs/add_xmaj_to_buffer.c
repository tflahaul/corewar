/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_x_to_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:46:43 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/12 14:13:17 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	add_if_not_type_neg(t_type *type, t_printf *data, t_dconv *var)
{
	if (!type->neg && type->width >= 0)
	{
		while (var->prec-- > var->len)
			ft_add_char_to_buff(data, '0');
		while (--var->len >= 0)
		{
			if (!var->nbr2 && type->precision && !type->prec)
				ft_add_char_to_buff(data, ' ');
			else
				ft_add_char_to_buff(data, var->str[var->len]);
		}
	}
	free_time(var);
}

static void	add_right_width(t_type *type, t_printf *data, t_dconv *var)
{
	var->len = ft_strlen(var->str);
	var->width -= (type->prec > var->len ? type->prec : var->len);
	if (type->sharp && var->nbr2 != 0)
		var->width -= 2;
	if (var->nbr2 > 0 && type->sharp && type->zero
		&& !type->neg && type->width >= 0)
	{
		ft_add_char_to_buff(data, '0');
		ft_add_char_to_buff(data, 'X');
	}
	while (var->width-- > 0)
	{
		if (type->zero && !type->neg && type->width >= 0 && !type->precision)
			ft_add_char_to_buff(data, '0');
		else
			ft_add_char_to_buff(data, ' ');
	}
	if (var->nbr2 > 0 && type->sharp && !type->zero
		&& !type->neg && type->width >= 0)
	{
		ft_add_char_to_buff(data, '0');
		ft_add_char_to_buff(data, 'X');
	}
	add_if_not_type_neg(type, data, var);
}

static void	add_if_type_neg(t_type *type, t_printf *data, t_dconv *var)
{
	if (type->neg || type->width < 0)
	{
		if (var->nbr2 > 0 && type->sharp)
			ft_add_char_to_buff(data, '0');
		if (var->nbr2 > 0 && type->sharp)
			ft_add_char_to_buff(data, 'X');
		while (var->prec-- > var->len)
			ft_add_char_to_buff(data, '0');
		while (--var->len >= 0)
		{
			if (!var->nbr2 && type->precision && !type->prec)
				ft_add_char_to_buff(data, ' ');
			else
				ft_add_char_to_buff(data, var->str[var->len]);
		}
	}
	add_right_width(type, data, var);
}

int			add_xmaj_to_buffer(t_type *type, t_printf *data, va_list *ap)
{
	t_dconv		*var;

	if (!(var = (t_dconv*)malloc(sizeof(t_dconv))))
		return (ERROR);
	ft_memset(var, 0, sizeof(t_dconv));
	if (!type->warning)
		var->nbr2 = (unsigned int)va_arg(*ap, unsigned int);
	else if (type->hh)
		var->nbr2 = (unsigned char)va_arg(*ap, unsigned int);
	else if (type->h)
		var->nbr2 = (unsigned short int)va_arg(*ap, unsigned int);
	else if (type->l)
		var->nbr2 = (unsigned long int)va_arg(*ap, unsigned long int);
	else if (type->ll)
		var->nbr2 = (unsigned long long int)va_arg(*ap, unsigned long long int);
	if (type->precision && !type->prec && !type->width && var->nbr2 == 0)
		return (free_error(var));
	var->prec = type->prec;
	ft_ntohtoa(var, "0123456789ABCDEF");
	if (!var->str)
		return (free_error(var));
	var->len = ft_strlen(var->str);
	var->width = (type->width < 0 ? -type->width : type->width);
	add_if_type_neg(type, data, var);
	return (0);
}
