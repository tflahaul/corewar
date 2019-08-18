/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/18 15:01:45 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void					op_lld(t_process *process, t_parameters *params)
{
	if (__likely(ISREG(params->tab[1])))
	{
		process->registers[params->tab[1]] = ft_binarray_to_int(process->pc + (params->tab[0] % IDX_MOD), 4);
		process->carry = !(process->registers[params->tab[1]]);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
