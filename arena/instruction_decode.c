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

#include <stdint.h>
#include <stdlib.h>

#include <libft.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>
#include <corewar_compiler.h>
/*
static t_ops const	instructions[] = {
	{0, 0, 0, 0},
	{0, 0x00A, 0, &op_live},
	{1, 0x005, 0, &op_ld},
	{1, 0x005, 0, &op_st},
	{1, 0x00A, 0, &op_add},
	{1, 0x00A, 0, &op_sub},
	{1, 0x006, 0, &op_and},
	{1, 0x006, 0, &op_or},
	{1, 0x006, 0, &op_xor},
	{0, 0x014, 0, &op_zjmp},
	{1, 0x019, 0, &op_ldi},
	{1, 0x019, 0, &op_sti},
	{0, 0x320, 0, &op_fork},
	{1, 0x00A, 0, &op_lld},
	{1, 0x032, 0, &op_lldi},
	{0, 0x3E8, 0, &op_lfork},
	{1, 0x002, 0, &op_aff},
	{0, 0, 0, 0}
};
*/
