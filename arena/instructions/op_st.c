/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:18 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/28 13:23:00 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void							op_st(t_process *process, t_parameters *params)
{
	register int				value;

	if (__likely(ISREG(params->tab[0])))
	{
		value = process->registers[params->tab[0]];
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			process->registers[params->tab[1]] = value;
		else
			ft_int_to_binarray(ft_safe_update_pc(process->pc, NEG_IDX(params->tab[1])), value);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
