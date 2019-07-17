/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:48:59 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 18:12:41 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <arena.h>
#include <arena_memory.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <list_torvalds.h>
#include <corewar_compiler.h>

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

int						ft_list_del(t_listhead *head)
{
	t_listhead			*node;
	t_listhead			*next;

	node = head->next;
	next = node->next;
	while (node != head)
	{
		free((void *)GET_PROC(node));
		node = next;
		next = node->next;
	}
	return (EXIT_SUCCESS);
}

int						ft_puterror_memalloc_failure(t_listhead *head)
{
	ft_puterror(ALLOCFAIL);
	ft_list_del(head);
	return (EXIT_ERROR);
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
