/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:29 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 15:38:46 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void						op_sub(t_process *process, t_parameters *params)
{
	register int32_t		sum;

	process->pc = MEMINDEX(process->pc + params->oplen + 1);
	if (params->ocp != RRR)
		return ;
	if (ISREG(params->tab[0]) && ISREG(params->tab[1])&& ISREG(params->tab[2]))
	{
		sum = process->registers[params->tab[0]] - process->registers[params->tab[1]];
		process->registers[params->tab[2]] = sum;
		process->carry = sum ? 0 : 1;
	}
}
