/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_log_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:23:46 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/01 18:49:12 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <gui.h>
#include <arena.h>

inline void						ft_print_winner(void)
{
	if (g_arena.last_alive)
		printf(LOG_WINNER, g_arena.last_alive->id, g_arena.last_alive->name);
}

inline void						ft_introduce_contestants(void)
{
	t_warrior	*node;

	node = g_arena.warriors;
	printf("Introducing contestants...\n");
	while (node)
	{
		printf(LOG_PLAYER, node->id, node->size, node->name);
		node = node->next;
	}
}
