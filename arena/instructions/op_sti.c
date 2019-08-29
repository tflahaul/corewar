/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/29 16:26:01 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_sti(t_process *process, t_parameters *params)
{
	register short			addr = 0;
	unsigned int			ret;

	if (__likely(ISREG(params->tab[0]) && (params->ocp & 192) >> 6 == REG_CODE))
	{
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			addr += process->registers[params->tab[1]];
		else
			addr += params->tab[1];
		if ((params->ocp & 12) >> 2 == REG_CODE && ISREG(params->tab[2]))
			addr += process->registers[params->tab[2]];
		else
			addr += params->tab[2];
		ret = ft_safe_update_pc(process->pc, NEG_IDX(addr));
		ft_int_to_binarray(ret, process->registers[params->tab[0]]);
		update_player_array(ret, process->registers[1]);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
