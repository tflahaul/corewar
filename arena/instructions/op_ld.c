/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:40 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/29 11:03:26 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_ld(t_process *proc, t_parameters *params)
{
	if (__likely(ISREG(params->tab[1])))
	{
		if ((params->ocp & 192) >> 6 == REG_CODE && ISREG(params->tab[0]))
			proc->registers[params->tab[1]] = proc->registers[params->tab[0]];
		else
			proc->registers[params->tab[1]] = params->tab[0];
		proc->registers[0] = !(proc->registers[params->tab[1]]);
	}
	proc->pc = MEMINDEX(proc->pc + params->oplen + 1);
}
