/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:00:41 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 12:40:23 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <libft.h>
#include <arena.h>
#include <arena_process.h>

void						op_live(t_process *prc, t_parameters *parameters)
{
	t_warrior				*warrior;

	if ((warrior = ft_get_warrior_from_id(parameters->tab[0])) != NULL)
	{
		printf("Un processus dit que le joueur %i est en vie\n", warrior->id);
		g_arena.last_alive = warrior;
		prc->live++;
	}
	prc->pc = MEMINDEX(prc->pc + parameters->oplen + 1);
}
