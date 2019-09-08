/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:36:13 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/08 10:28:38 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static t_ops const		g_opset[] = {
	{0, 0, 0, 0, 0, 0},
	{&op_live, 0, 0x00a, 0, 4, 0x000},
	{&op_ld, 1, 0x005, 1, 4, 0x001},
	{&op_st, 0, 0x005, 1, 4, 0x000},
	{&op_add, 1, 0x00a, 1, 4, 0x000},
	{&op_sub, 1, 0x00a, 1, 4, 0x000},
	{&op_and, 1, 0x006, 1, 4, 0x002},
	{&op_or, 1, 0x006, 1, 4, 0x002},
	{&op_xor, 1, 0x006, 1, 4, 0x002},
	{&op_zjmp, 0, 0x014, 0, 2, 0x000},
	{&op_ldi, 0, 0x019, 1, 2, 0x001},
	{&op_sti, 0, 0x019, 1, 2, 0x000},
	{&op_fork, 0, 0x320, 0, 2, 0x000},
	{&op_lld, 1, 0x00a, 1, 4, 0x002},
	{&op_lldi, 1, 0x032, 1, 2, 0x002},
	{&op_lfork, 0, 0x3e8, 0, 2, 0x00},
	{&op_aff, 0, 0x002, 1, 4, 0x000}
};

static inline int		ft_update_oplength(t_process *prc, t_parameters *data)
{
	int					size;
	unsigned char const	byte = (data->ocp >> (6 - (2 * data->index++))) & 0x03;

	size = 0;
	if (byte == REG_CODE)
		size = 1;
	else if (byte == DIR_CODE)
		size = prc->instruction.dirsize;
	else if (byte == IND_CODE)
		size = 8;
	return (size);
}

static inline int		ft_get_op_parameter(t_process *prc, t_parameters *data)
{
	int					value;
	int const			size = ft_update_oplength(prc, data);

	if (size != 8)
	{
		value = ft_binarray_to_int(prc->pc + data->oplen + 1, size);
		data->oplen += size;
	}
	else
	{
		value = ft_binarray_to_int(prc->pc + data->oplen + 1, 2);
		if (prc->instruction.readmem > 0)
			value = ft_binarray_to_int(ft_safe_update_pc(prc->pc,\
				(prc->instruction.readmem > 1 ? value : NEG_IDX(value))),\
				(prc->instruction.funptr == &op_ldi\
				|| prc->instruction.funptr == &op_lldi) ? 2 : 4);
		data->oplen += 2;
	}
	return (value);
}

void					ft_fetch_instruction(t_process *proc, t_parameters *par)
{
	unsigned int const	opc = g_arena.arena[proc->pc];

	if (LIKELY(opc > 0 && opc < 17))
	{
		proc->instruction = g_opset[opc];
		ft_bzero(&(proc->params), sizeof(t_parameters));
		if (g_opset[opc].has_code_byte)
		{
			par->oplen = 1;
			par->ocp = g_arena.arena[MEMINDEX(proc->pc + 1)];
			par->tab[0] = ft_get_op_parameter(proc, par);
			par->tab[1] = ft_get_op_parameter(proc, par);
			par->tab[2] = ft_get_op_parameter(proc, par);
		}
		else
		{
			par->oplen = g_opset[opc].dirsize;
			par->tab[0] = ft_binarray_to_int(proc->pc + 1, par->oplen);
		}
	}
	else
		proc->pc = MEMINDEX(proc->pc + 1);
}
