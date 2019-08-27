/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:00:45 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/27 20:55:09 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void					op_zjmp(t_process *process, t_parameters *parameters)
{
	if (process->registers[0] != 0)
		process->pc = ft_update_program_counter(process->pc, NEG_IDX(parameters->tab[0]));
	else
		process->pc = MEMINDEX(process->pc + parameters->oplen + 1);
}
