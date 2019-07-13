/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_memory_management.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:48:59 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/13 11:35:59 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <arena.h>
#include <arena_memory.h>

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
