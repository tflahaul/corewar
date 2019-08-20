/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:29 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/19 14:51:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_and(t_process *process, t_parameters *params)
{
	register int			p1;
	register int			p2;

	if (__likely(ISREG(params->tab[2])))
	{
		if ((params->ocp & 192) >> 6 == REG_CODE && ISREG(params->tab[0]))
			p1 = process->registers[params->tab[0]];
		else
			p1 = params->tab[0];
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			p2 = process->registers[params->tab[1]];
		else
			p2 = params->tab[1];
		process->registers[params->tab[2]] = (p1 & p2);
		process->carry = !(process->registers[params->tab[2]]);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
