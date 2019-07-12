/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_uint16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:57 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 10:49:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint16_t					ft_swap_uint16(uint16_t nb)
{
	return (((nb & 0x00ff) >> 8) | ((nb & 0xff00) << 8));
}