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

#define DEBUG
#include <stdio.h>

#include <stdint.h>
#include <stdlib.h>

#include <op.h>
#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>

static t_ops const		instructions[] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0}, // live
	{0, 1, 0, 1}, // ld
	{0, 0, 0, 1}, // st
	{0, 1, 0, 1}, // add
	{0, 1, 0, 1}, // sub
	{0, 1, 0, 1}, // and
	{0, 1, 0, 1}, // or
	{0, 1, 0, 1}, // xor
	{0, 0, 0, 0}, // zjmp
	{0, 0, 0, 1}, // ldi
	{0, 0, 0, 1}, // sti
	{0, 0, 0, 0}, // fork
	{0, 1, 0, 1}, // lld
	{0, 1, 0, 1}, // lldi
	{0, 0, 0, 0}, // lfork
	{0, 0, 0, 1}, // aff
	{0, 0, 0, 0}
};

static void				ft_putbinary(unsigned char octet)
{
	for (unsigned int pow = (1 << 7); pow; pow >>= 1)
		printf("%i", !!(pow & octet));
	printf("\t%#x\n", octet);
}

static int				ft_get_instruction_parameters(unsigned char octet)
{
	unsigned int		index;
	unsigned char		temp;

	index = 0;
	ft_putbinary(octet);
	while (index < 3)
	{
		temp = (octet >> (6 - (index * 2))) & 0x03;
		if (temp == REG_CODE)
			printf("Param #%u = Addressage registre\n", index + 1);
		else if (temp == DIR_CODE)
			printf("Param #%u = Addressage direct\n", index + 1);
		else if (temp == IND_CODE)
			printf("Param #%u = Addressage indirect\n", index + 1);
		++index;
	}
#ifdef DEBUG
	if (__unlikely(octet & 0x03))
	{
		printf("ERREUR:Mauvais octet de codage des paramètres\n\n");
		return (0);
	}
#endif
	return (1);
}

void					ft_decode_instruction(t_process *process)
{
	__attribute__((unused)) void (*funptr)(t_process *, t_param *);
	unsigned int const	index = g_arena.arena[process->pc];

	if (__likely(index > 0 && index < 18))
	{
		funptr = instructions[index].funptr;
		if (instructions[index].has_code_byte)
			ft_get_instruction_parameters(g_arena.arena[(process->pc = MEMINDEX(process->pc + 1))]);
		else
			printf("Pas d'octet de codage pour l'instruction %#x\n", index);
		process->pc = MEMINDEX(process->pc + 2);
		if (instructions[index].carry)
			FLIPCARRY(process->carry);
	}
	else {
#ifdef DEBUG
		printf("Instruction %#x inexistante\n", index);
#endif
		process->pc = MEMINDEX(process->pc + 1);
	}
}
