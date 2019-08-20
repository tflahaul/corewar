/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:25 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/16 15:53:41 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_aff(t_process *process, t_parameters *params)
{
	if (__likely(ISREG(params->tab[0])) && (g_arena.options & OPTION_P))
		ft_putchar((char)(process->registers[params->tab[0]]));
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
