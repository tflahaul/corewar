/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_log_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:23:46 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/28 15:38:46 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <gui.h>
#include <arena.h>

#define LOG_WINNER				"Player %i '%s' has won the game\n"
#define LOG_PLAYER				"* Player %i, weighing %3i bytes, '%s'\n"

inline void						ft_print_winner(void)
{
	if (g_arena.last_alive)
		printf(LOG_WINNER, g_arena.last_alive->id, g_arena.last_alive->name);
}

inline void						ft_introduce_contestants(void)
{
	printf("Introducing contestants...\n");
	for (t_warrior *node = g_arena.warriors; node; (node = node->next))
		printf(LOG_PLAYER, node->id, node->size, node->name);
}
