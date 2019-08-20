/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:18 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/14 16:03:00 by thflahau         ###   ########.fr       */
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
		if (ISREG(params->tab[1]) && (params->ocp & 48) >> 4 == REG_CODE)
			process->registers[params->tab[1]] = value;
		else
			ft_int_to_binarray(ft_update_program_counter(process->pc, (params->tab[1] % IDX_MOD)), value);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
