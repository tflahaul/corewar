/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:28:25 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/11 15:57:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arena.h>
#include <arena_process.h>
#include <corewar_compiler.h>

void						op_aff(t_process *process, t_parameters *params)
{
	if (__likely(ISREG(params->tab[0])))
		ft_putchar(process->registers[params->tab[1]] % 256);
	process->pc = MEMINDEX(process->pc + params->oplen + 1);
}
