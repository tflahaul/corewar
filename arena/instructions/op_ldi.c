/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:44 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/18 12:59:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_ldi(t_process *process, t_parameters *params)
{
	register int			value;
	register int const		address = params->tab[0] + params->tab[1];

	if (__likely(ISREG(params->tab[2])))
	{
		value = ft_binarray_to_int(process->pc + (address % IDX_MOD), REG_SIZE);
		process->registers[params->tab[2]] = value;
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
