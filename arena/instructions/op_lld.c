/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/19 14:34:00 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void					op_lld(t_process *proc, t_parameters *params)
{
	if (LIKELY(ISREG(params->tab[1])))
	{
		if ((params->ocp & 192) >> 6 == REG_CODE && ISREG(params->tab[0]))
			proc->registers[params->tab[1]] = proc->registers[params->tab[0]];
		else
			proc->registers[params->tab[1]] = params->tab[0];
		proc->registers[0] = !(proc->registers[params->tab[1]]);
	}
	proc->pc = MEMINDEX(proc->pc + params->oplen + 1);
}
