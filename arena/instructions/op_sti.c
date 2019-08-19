/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/19 14:53:50 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_sti(t_process *process, t_parameters *params)
{
	register int32_t		addr = 0;

	if (__likely(ISREG(params->tab[0]) && (params->ocp & 192) >> 6 == REG_CODE))
	{
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			addr += process->registers[params->tab[1]];
		else if ((params->ocp & 48) >> 4 == IND_CODE)
			addr += ft_binarray_to_int(process->pc + params->tab[1], 2);
		else
			addr += params->tab[1];
		if ((params->ocp & 12) >> 2 == REG_CODE && ISREG(params->tab[2]))
			addr += process->registers[params->tab[2]];
		else
			addr += params->tab[2];
		ft_int_to_binarray(process->pc + (addr % IDX_MOD), process->registers[params->tab[0]]);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
