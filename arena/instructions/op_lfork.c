/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/12 14:33:37 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>
#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_lfork(t_process *process, t_parameters *params)
{
	t_process				*node;

	if (__unlikely(!(node = (t_process *)malloc(sizeof(t_process)))))
		return ;
	ft_memcpy(node, process, sizeof(*process));
	node->pc = MEMINDEX(process->pc + params->tab[0]);
	ft_list_push(&(node->list), &(process->list));
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
