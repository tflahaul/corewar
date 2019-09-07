/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:44 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/28 13:22:43 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_ldi(t_process *process, t_parameters *params)
{
	register int			value;
	register short			address = 0;

	if (LIKELY(ISREG(params->tab[2])))
	{
		if ((params->ocp & 192) >> 6 == REG_CODE && ISREG(params->tab[0]))
			address += NEG_IDX(process->registers[params->tab[0]]);
		else
			address += NEG_IDX(params->tab[0]);
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			address += NEG_IDX(process->registers[params->tab[1]]);
		else
			address += NEG_IDX(params->tab[1]);
		value = ft_binarray_to_int(process->pc + address, REG_SIZE);
		process->registers[params->tab[2]] = value;
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
