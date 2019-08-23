/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:57 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/19 14:46:15 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_lldi(t_process *process, t_parameters *params)
{
	register int			value;
	register short			address = 0;

	if (__likely(ISREG(params->tab[2])))
	{
		if ((params->ocp & 192) >> 6 == REG_CODE && ISREG(params->tab[0]))
			address += process->registers[params->tab[0]];
		else
			address += params->tab[0];
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			address += process->registers[params->tab[1]];
		else
			address += params->tab[1];
		value = ft_binarray_to_int(ft_update_program_counter(process->pc, address), 4);
		process->registers[params->tab[2]] = value;
		process->registers[0] = !(value);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
