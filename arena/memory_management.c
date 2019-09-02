/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:48:59 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/02 12:24:49 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void					ft_hexdump_memory(void)
{
	uint16_t			index = 0;

	ft_printf("0x%#.4x:  ", index);
	while (index < MEM_SIZE)
	{
		ft_printf("%02hhx", g_arena.arena[index]);
		if (!(++index % 64))
		{
			ft_putchar('\n');
			ft_printf("%#.4x:  ", index);
		}
		else
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void					*ft_get_process(t_listhead *node)
{
	return ((void *)((char *)node - offsetof(t_process, list)));
}

void					ft_free_warriors(void)
{
	t_warrior			*ptr;
	t_warrior			*temp;

	temp = g_arena.warriors;
	while (temp != NULL)
	{
		ptr = temp->next;
		free((void *)temp);
		temp = ptr;
	}
}
