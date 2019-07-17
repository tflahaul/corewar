/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:48:59 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 15:23:02 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <arena.h>
#include <arena_memory.h>

void					ft_hexdump_memory(void)
{
	uint16_t			index = 0;

	printf("0x%#.5x:  ", index);
	while (index < MEM_SIZE)
	{
		printf("%02hhx", g_arena.arena[index]);
		if (!(++index % 32))
		{
			printf("\n");
			printf("%#.5x:  ", index);
		}
		else
			printf(" ");
	}
	printf("\n");
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
