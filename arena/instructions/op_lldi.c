/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:57 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 16:29:46 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_lldi(t_process *process, t_parameters *params)
{
	register int			value;

	if (__likely(ISREG(params->tab[2])))
	{
		value = ft_binarray_to_int((params->tab[0] + params->tab[1]), REG_SIZE);
		process->registers[params->tab[2]] = value;
		FLIPCARRY(process->carry);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}

