/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_int32.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:31:02 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/28 12:31:30 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
**	Reverse the byte order of 32 bits integer nb. This function is
**	only used for conversion between little and big endian values.
*/

int32_t						ft_swap_int32(int32_t nb)
{
	return (((nb & 0xff000000) >> 24) | ((nb & 0x00ff0000) >> 8) |
			((nb & 0x0000ff00) << 8) | ((nb & 0x000000ff) << 24));
}
