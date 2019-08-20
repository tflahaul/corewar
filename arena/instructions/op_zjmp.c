/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:00:45 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 15:45:10 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>

void					op_zjmp(t_process *process, t_parameters *parameters)
{
	if (process->carry != 0)
		process->pc = ft_update_program_counter(process->pc, (parameters->tab[0] % IDX_MOD));
	else
		process->pc = MEMINDEX(process->pc + parameters->oplen + 1);
}
