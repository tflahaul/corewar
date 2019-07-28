/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_uint32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:24:00 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/28 12:30:02 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
**	Reverse the byte order of 32 bits unsigned integer nb. This function
**	is only used for conversion between little and big endian values.
*/

uint32_t					ft_swap_uint32(uint32_t nb)
{
	return (((nb & 0xff000000) >> 24) | ((nb & 0x00ff0000) >> 8) |
			((nb & 0x0000ff00) << 8) | ((nb & 0x000000ff) << 24));
}
