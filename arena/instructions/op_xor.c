/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:35 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/16 15:47:49 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_xor(t_process *process, t_parameters *params)
{
	if (__likely(ISREG(params->tab[2])))
	{
		process->registers[params->tab[2]] = (params->tab[0] ^ params->tab[1]);
		process->carry = !(process->registers[params->tab[2]]);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
