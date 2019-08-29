/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/28 13:23:04 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_sti(t_process *process, t_parameters *params)
{
	register short			addr = 0;

	if (__likely(ISREG(params->tab[0]) && (params->ocp & 192) >> 6 == REG_CODE))
	{
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			addr += NEG_IDX(process->registers[params->tab[1]]);
		else
			addr += NEG_IDX(params->tab[1]);
		if ((params->ocp & 12) >> 2 == REG_CODE && ISREG(params->tab[2]))
			addr += NEG_IDX(process->registers[params->tab[2]]);
		else
			addr += NEG_IDX(params->tab[2]);
		ft_int_to_binarray(ft_safe_update_pc(process->pc, addr), process->registers[params->tab[0]]);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
