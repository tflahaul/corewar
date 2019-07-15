/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:06 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/15 14:02:58 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arena.h>
#include <string.h>

static inline unsigned int	ft_compute_gap_between_warriors(void)
{
	return ((unsigned int)(MEM_SIZE / ft_list_size_warrior()));
}

void						ft_arena_load_warriors(void)
{
	t_warrior				*node;
	register uint8_t		*arena;

	arena = g_arena.arena;
	node = g_arena.warriors;
	while (node != NULL)
	{
		ft_memcpy(arena, node->program, node->size);
		arena += ft_compute_gap_between_warriors();
		node = node->next;
	}
}
