/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_warrior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:05:07 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 12:39:19 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>

inline t_warrior		*ft_get_warrior_from_id(int id)
{
	t_warrior			*node;

	node = g_arena.warriors;
	while (node != NULL)
	{
		if (node->id == id)
			return (node);
		node = node->next;
	}
	return (NULL);
}

inline int				ft_number_in_list(int32_t id)
{
	t_warrior			*node;

	node = g_arena.warriors;
	while (node != NULL)
	{
		if (node->id == id)
			return (EXIT_FAILURE);
		node = node->next;
	}
	return (EXIT_SUCCESS);
}

unsigned int			ft_list_size_warrior(void)
{
	t_warrior			*node;
	unsigned int		size;

	size = 0;
	node = g_arena.warriors;
	while (node != NULL && ++size)
		node = node->next;
	return (size);
}

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
			ft_bzero(node, sizeof(*node));
			g_arena.warriors = node;
		}
		else
			return (ft_puterror(strerror(errno)));
	}
	else
	{
		if ((node = (t_warrior *)malloc(sizeof(*node))) != NULL)
			ft_bzero(node, sizeof(*node));
		else
			return (ft_puterror(strerror(errno)));
		ft_list_push_warrior(node);
	}
	g_arena.size++;
	return (EXIT_SUCCESS);
}
