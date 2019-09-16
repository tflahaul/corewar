/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endian_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:assembler/libft/ft_putchar.c
/*   Created: 2019/04/10 18:54:20 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/11 22:33:18 by abrunet          ###   ########.fr       */
=======
/*   Created: 2019/09/09 12:13:26 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/09 12:13:39 by thflahau         ###   ########.fr       */
>>>>>>> norme:libft/ft_endian_swap.c
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t						ft_endian_swap(uint32_t nb)
{
	return (((nb & 0xff000000) >> 24) | ((nb & 0x00ff0000) >> 8)\
		| ((nb & 0x0000ff00) << 8) | ((nb & 0x000000ff) << 24));
}
