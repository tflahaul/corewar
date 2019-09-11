/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:33 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/04 11:05:04 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_fork(t_process *process, t_parameters *params)
{
	t_process				*node;

	if (LIKELY((node = (t_process *)malloc(sizeof(t_process))) != NULL))
	{
		ft_memcpy(node, process, sizeof(*process));
		node->pc = ft_safe_update_pc(process->pc, NEG_IDX(params->tab[0]));
		ft_bzero(&(node->params), sizeof(t_parameters));
		RESET_PROCESS(node);
		ft_list_push(&(node->list), process->head->prev);
		++g_arena.processes;
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
