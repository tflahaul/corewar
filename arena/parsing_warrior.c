/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_warrior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:46:39 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/08 18:56:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include "../corewar_compiler.h"
#include "../arena_errors.h"
#include "../arena.h"

// Pas testé du tout
static t_warrior			*ft_add_new_warrior_to_list(void)
{
	t_warrior				*temp;
	t_warrior				*node;

	node = NULL;
	if (g_arena.warriors == NULL)
	{
		g_arena.warriors = (t_warrior *)malloc(sizeof(t_warrior));
		if (__likely(g_arena.warriors != NULL))
			memset(g_arena.warriors, 0, sizeof(t_warrior));
		return (g_arena.warriors);
	}
	else
	{
		temp = g_arena.warriors;
		while (temp->next != NULL)
			temp = temp->next;
		node = (t_warrior *)malloc(sizeof(*node));
		temp->next = node;
	}
	return (node);
}

int							ft_parse_warrior(char const *file)
{
	int						fd;

	if (__unlikely((fd = open(file, O_RDONLY)) < 0))
		return (ft_puterror(strerror(errno)));
	if (__unlikely(ft_fetch_and_check_metadata(fd) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
// Store programs code next
	if (__unlikely(close(fd) < 0))
		return (ft_puterror(strerror(errno)));
	return (EXIT_SUCCESS);
}
