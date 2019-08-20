/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:33 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/14 14:11:43 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>
#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_fork(t_process *process, t_parameters *params)
{
	t_process				*node;

	if (__likely((node = (t_process *)malloc(sizeof(t_process))) != NULL))
	{
		ft_memcpy(node, process, sizeof(*process));
		node->pc = ft_update_program_counter(process->pc, (params->tab[0] % IDX_MOD));
		ft_bzero(&(node->params), sizeof(t_parameters));
		RESET_PROCESS(node);
		ft_list_push(&(node->list), node->head);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
