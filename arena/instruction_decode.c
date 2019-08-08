/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:36:13 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/22 16:46:49 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static t_ops const		opset[] = {
	{0, 0, 0, 0, 0},
	{0, 0, 0x00a, 0, 4}, // live
	{0, 1, 0x005, 1, 4}, // ld
	{0, 0, 0x005, 1, 4}, // st
	{0, 1, 0x00a, 1, 4}, // add
	{0, 1, 0x00a, 1, 4}, // sub
	{0, 1, 0x006, 1, 4}, // and
	{0, 1, 0x006, 1, 4}, // or
	{0, 1, 0x006, 1, 4}, // xor
	{&op_zjmp, 0, 0x014, 0, 2}, // zjmp
	{0, 0, 0x019, 1, 2}, // ldi
	{0, 0, 0x019, 1, 2}, // sti
	{0, 0, 0x320, 0, 2}, // fork
	{0, 1, 0x00a, 1, 4}, // lld
	{0, 1, 0x032, 1, 2}, // lldi
	{0, 0, 0x3e8, 0, 2}, // lfork
	{0, 0, 0x002, 1, 4}  // aff
};

static unsigned int		ft_get_oplength(uint32_t dsize, uint8_t octet)
{
	uint8_t				temp;
	unsigned int		index;
	unsigned int		length;

	index = 0;
	length = 1;
	while (index < 3)
	{
		temp = (octet >> (6 - (2 * index++))) & 0x03;
		if (temp == REG_CODE)
			length += 1;
		else if (temp == DIR_CODE)
			length += dsize;
		else if (temp == IND_CODE)
			length += 2;
	}
	return (length);
}

/*
**	On utilise un tableau d'entiers pour stocker les paramètres.
**	parameters[0] = octet de codage des paramètres
**	parameters[1..3] = valeurs des paramètres
*/
#include <stdio.h>

void					ft_fetch_instruction(t_process *process)
{
	unsigned int		length = 0;
	unsigned int		parameters[4];
	unsigned int const	opc = g_arena.arena[process->pc];

	if (__likely(opc > 0 && opc < 18))
	{
		printf("Decoding instruction %#.2x...\n", opc);
		process->cycle = opset[opc].cycle;
		if (opset[opc].has_code_byte)
		{
			length = ft_get_oplength(opset[opc].dirsize, g_arena.arena[MEMINDEX(process->pc + 1)]);
			process->pc = MEMINDEX(process->pc + length + 1);
		}
		else if (opc == 9) /* juste pour test zjmp */
		{
			length = opset[opc].dirsize;
			parameters[1] = ft_binarray_to_int((uint32_t)MEMINDEX(process->pc + 1), length);
			(*opset[opc].funptr)(process, parameters);
		}
		else
			process->pc = MEMINDEX(process->pc + opset[opc].dirsize + 1);
	}
	else
		process->pc = MEMINDEX(process->pc + 1);
}
