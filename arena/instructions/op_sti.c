/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 16:13:35 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void					op_sti(t_process *process, t_parameters *params)
{
	register int		addr = 0;

	if (__likely(ISREG(params->tab[0])))
	{
		if ((params->ocp & 48) == REG_CODE && ISREG(params->tab[1]))
			addr += process->registers[params->tab[1]];
		else
			addr += params->tab[1];
		if ((params->ocp & 12) == REG_CODE && ISREG(params->tab[2]))
			addr += process->registers[params->tab[2]];
		else
			addr += params->tab[2];
		g_arena.arena[MEMINDEX(addr % IDX_MOD)] = process->registers[params->tab[0]];
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
