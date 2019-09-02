/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:27:19 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/07 11:27:23 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void		ft_add_char_to_buff(t_printf *data, char c)
{
	data->buffer[data->actual++] = c;
	if (data->actual == BUFF_SIZE)
		ft_putbuffer(data);
}

void		ft_putbuffer(t_printf *data)
{
	write(1, data->buffer, data->actual);
	data->ret += data->actual;
	data->actual = 0;
}
