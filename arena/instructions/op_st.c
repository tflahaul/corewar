/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:18 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 16:19:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void							op_st(t_process *process, t_parameters *params)
{
	register int32_t			value;

	if (__likely(ISREG(params->tab[0])))
	{
		value = process->registers[params->tab[0]];
		if ((params->ocp & 48) >> 4 == REG_CODE && ISREG(params->tab[1]))
			process->registers[params->tab[1]] = value;
		else
			g_arena.arena[MEMINDEX(params->tab[1] % IDX_MOD)] = value;
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
