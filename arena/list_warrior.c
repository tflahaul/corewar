/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_warrior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:05:07 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 14:35:34 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include <arena.h>
#include <arena_errors.h>

static inline void		ft_list_push_warrior(t_warrior *entry)
{
	if (__builtin_expect((g_arena.warriors == NULL), 0))
		g_arena.warriors = entry;
	else if (__builtin_expect(entry != NULL, 1))
	{
		entry->next = g_arena.warriors;
		g_arena.warriors = entry;
	}
}

int						ft_malloc_new_warrior(void)
{
	t_warrior			*node;

	if (g_arena.warriors == NULL)
	{
		if ((node = (t_warrior *)malloc(sizeof(*node))) != NULL)
		{
			__builtin_memset(node, 0, sizeof(*node));
			g_arena.warriors = node;
		}
		else
			return (ft_puterror(strerror(errno)));
	}
	else
	{
		if ((node = (t_warrior *)malloc(sizeof(*node))) != NULL)
			__builtin_memset(node, 0, sizeof(*node));
		else
			return (ft_puterror(strerror(errno)));
		ft_list_push_warrior(node);
	}
	return (EXIT_SUCCESS);
}
