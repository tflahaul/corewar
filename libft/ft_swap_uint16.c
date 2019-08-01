/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_uint16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:57 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/28 12:29:59 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
**	Reverse the byte order of 16 bits unsigned integer nb. This function
**	is only used for conversion between little and big endian values.
*/

uint16_t					ft_swap_uint16(uint16_t nb)
{
	return (((nb & 0x00ff) >> 8) | (uint16_t)((nb & 0xff00) << 8));
}
