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
	register int			i;
	register int			j;

	if (__likely(ISREG(params->tab[2])))
	{
		if ((params->ocp & 192) >> 6 == REG_CODE && ISREG(params->tab[0]))
			i = process->registers[params->tab[0]];
		else
			i = params->tab[0];
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			j = process->registers[params->tab[1]];
		else
			j = params->tab[1];
		process->registers[params->tab[2]] = (i & j);
		process->carry = !(process->registers[params->tab[2]]);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
