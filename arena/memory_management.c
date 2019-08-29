/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:48:59 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/27 16:23:43 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void					ft_hexdump_memory(void)
{
	uint16_t			index = 0;

	printf("0x%#.4x:  ", index);
	while (index < MEM_SIZE)
	{
		printf("%02hhx", g_arena.arena[index]);
		if (!(++index % 64))
		{
			printf("\n");
			printf("%#.4x:  ", index);
		}
		else
			printf(" ");
	}
	printf("\n");
}

void					*ft_get_process(t_listhead *node)
{
	return ((void *)((char *)node - offsetof(t_process, list)));
}

inline void				ft_init_process_list(t_listhead lst[MAX_PLAYERS])
{
	ft_list_init_head(&(lst[0]));
	ft_list_init_head(&(lst[1]));
	ft_list_init_head(&(lst[2]));
	ft_list_init_head(&(lst[3]));
}

inline void				ft_delete_process_list(t_listhead lst[MAX_PLAYERS])
{
	ft_list_delete(&(lst[0]), &ft_get_process);
	ft_list_delete(&(lst[1]), &ft_get_process);
	ft_list_delete(&(lst[2]), &ft_get_process);
	ft_list_delete(&(lst[3]), &ft_get_process);
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
