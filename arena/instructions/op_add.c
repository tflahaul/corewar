/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:08 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/14 14:24:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void						op_add(t_process *proc, t_parameters *params)
{
	register int32_t		sum;

	if (ISREG(params->tab[0]) && ISREG(params->tab[1]) && ISREG(params->tab[2]))
	{
		sum = proc->registers[params->tab[0]] + proc->registers[params->tab[1]];
		proc->registers[params->tab[2]] = sum;
		proc->registers[0] = !(sum);
	}
	proc->pc = MEMINDEX(proc->pc + params->oplen + 1);
}
