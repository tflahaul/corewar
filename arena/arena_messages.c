/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:23:46 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/02 12:26:42 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arena.h>
#include <unistd.h>

#define LOG_WINNER				"Player %i, '%s', has won the game!\n"
#define LOG_PLAYER				"* Player %i, weighing %3i bytes, '%s'\n"

inline void						ft_print_winner(void)
{
	if (g_arena.last_alive != NULL)
		ft_printf(LOG_WINNER, g_arena.last_alive->id, g_arena.last_alive->name);
}

inline void						ft_introduce_contestants(void)
{
	t_warrior					*node;

	node = g_arena.warriors;
	write(STDOUT_FILENO, "Introducing contestants...\n", 27);
	while (node != NULL)
	{
		ft_printf(LOG_PLAYER, node->id, node->size, node->name);
		node = node->next;
	}
}
