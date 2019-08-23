/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:40 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/19 14:33:10 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_ld(t_process *process, t_parameters *params)
{
	if (__likely(ISREG(params->tab[1])))
	{
		process->registers[params->tab[1]] = params->tab[0];
		process->registers[0] = !(process->registers[params->tab[1]]);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
