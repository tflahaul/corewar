/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:18 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/02 09:35:05 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void							op_st(t_process *process, t_parameters *params)
{
	unsigned int				ret;
	register int				value;

	if (__likely(ISREG(params->tab[0])))
	{
		value = process->registers[params->tab[0]];
		if (ISREG(params->tab[1]) && (params->ocp & 48) >> 4 == REG_CODE)
			process->registers[params->tab[1]] = value;
		else
		{
			ret = ft_safe_update_pc(process->pc, NEG_IDX(params->tab[1]));
			ft_int_to_binarray(ret , value);
			update_player_array(ret, process->idx);
		}
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
