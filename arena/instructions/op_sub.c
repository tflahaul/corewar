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

void						op_sub(t_process *process, t_parameters *params)
{
	register int			sub;

	if (ISREG(params->tab[0]) && ISREG(params->tab[1]) && ISREG(params->tab[2]))
	{
		sub = process->registers[params->tab[0]] - process->registers[params->tab[1]];
		process->registers[params->tab[2]] = sub;
		process->registers[0] = !(sub);
	}
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
