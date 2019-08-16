/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:57 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/16 15:47:39 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_lldi(t_process *process, t_parameters *params)
{
	register int			value;
	register int			address;

	if (__likely(ISREG(params->tab[2])))
	{
		address = process->pc + (params->tab[0] % IDX_MOD);
		address += process->pc + (params->tab[1] % IDX_MOD);
		value = ft_binarray_to_int(address, REG_SIZE);
		process->registers[params->tab[2]] = value;
		process->carry = !(value);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
