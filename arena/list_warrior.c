/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_warrior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:05:07 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 12:35:58 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <arena.h>

void					ft_list_push_warrior(t_warrior *entry)
{
	if (__builtin_expect((g_arena.warriors == NULL), 0))
		g_arena.warriors = &entry;
	else
	{
		entry->next = *g_arena.warriors;
		g_arena.warriors = &entry;
	}
}

void					ft_malloc_new_warrior(void)
{
	t_warrior			*node;

	if (g_arena.warriors == NULL)
	{
		if ((*g_arena.warriors = (t_warrior *)malloc(sizeof(t_warrior))) != NULL)
			__builtin_memset(g_arena.warriors, 0, sizeof(t_warrior));
	}
	else
	{
		if ((node = (t_warrior *)malloc(sizeof(*node))) != NULL)
			__builtin_memset(node, 0, sizeof(*node));
		ft_list_push_warrior(node);
	}
}
