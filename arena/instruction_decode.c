/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:36:13 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/12 14:41:13 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <op.h>
#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static t_ops const		g_opset[] = {
	{0, 0, 0, 0, 0},
	{&op_live, 0, 0x00a, 0, 4}, // live
	{&op_ld  , 1, 0x005, 1, 4}, // ld
	{&op_st  , 0, 0x005, 1, 4}, // st
	{&op_add , 1, 0x00a, 1, 4}, // add
	{&op_sub , 1, 0x00a, 1, 4}, // sub
	{&op_and , 1, 0x006, 1, 4}, // and
	{&op_or  , 1, 0x006, 1, 4}, // or
	{&op_xor , 1, 0x006, 1, 4}, // xor
	{&op_zjmp, 0, 0x014, 0, 2}, // zjmp
	{&op_ldi , 0, 0x019, 1, 2}, // ldi
	{&op_sti , 0, 0x019, 1, 2}, // sti
	{&op_fork, 0, 0x320, 0, 2}, // fork
	{&op_lld , 1, 0x00a, 1, 4}, // lld
	{&op_lldi, 1, 0x032, 1, 2}, // lldi
	{&op_lfork, 0, 0x3e8, 0, 2}, // lfork
	{&op_aff , 0, 0x002, 1, 4}  // aff
};

static inline int		ft_update_oplength(t_process *prc, t_parameters *data)
{
	int					size = 0;
	unsigned char const	byte = (data->ocp >> (6 - (2 * data->index++))) & 0x03;

	size = 0;
	if (byte == REG_CODE)
		size = 1;
	else if (byte == DIR_CODE)
		size = prc->instruction.dirsize;
	else if (byte == IND_CODE)
		size = 2;
	return (size);
}

static inline int		ft_get_op_parameter(t_process *prc, t_parameters *data)
{
	int const			size = ft_update_oplength(prc, data);
	int const			value = ft_binarray_to_int(prc->pc + data->oplen + 1, size);

	data->oplen += size;
	return (value);
}

void					ft_fetch_instruction(t_process *process, t_parameters *parameters)
{
	unsigned int const	opc = g_arena.arena[process->pc];

	if (__likely(opc > 0 && opc < 18))
	{
		process->instruction = g_opset[opc];
		ft_bzero(parameters, sizeof(*parameters));
		if (g_opset[opc].has_code_byte)
		{
			parameters->oplen = 1;
			parameters->ocp = g_arena.arena[MEMINDEX(process->pc + 1)];
			for (unsigned int i = 0; i < 3; ++i)
				parameters->tab[i] = ft_get_op_parameter(process, parameters);
		}
		else
		{
			parameters->oplen = g_opset[opc].dirsize;
			parameters->tab[0] = ft_binarray_to_int(process->pc + 1, parameters->oplen);
		}
	}
	else
		process->pc = MEMINDEX(process->pc + 1);
}
