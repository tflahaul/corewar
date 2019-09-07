/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:29:29 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/19 14:02:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void						op_sub(t_process *proc, t_parameters *params)
{
	register int			sub;

	if (ISREG(params->tab[0]) && ISREG(params->tab[1]) && ISREG(params->tab[2]))
	{
		sub = proc->registers[params->tab[0]] - proc->registers[params->tab[1]];
		proc->registers[params->tab[2]] = sub;
		proc->registers[0] = !(sub);
	}
	proc->pc = MEMINDEX(proc->pc + params->oplen + 1);
}
