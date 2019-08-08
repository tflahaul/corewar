/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:23:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 10:31:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_PROCESS_H
# define ARENA_PROCESS_H

# include <stdint.h>

# include "list.h"
# include "op.h"

typedef struct			s_process
{
	t_listhead			list;
	int32_t				registers[REG_NUMBER + 1];
	uint32_t			live;
	uint16_t			carry;
	uint16_t			cycle;
	uint16_t			pc;
}						t_process;

# pragma pack(push, 2)

typedef struct			s_instructions {
	void				(*funptr)(t_process *, uint32_t[4]);
	unsigned int		carry;
	unsigned int		cycle;
	unsigned int		has_code_byte;
	unsigned int		dirsize;
}						t_ops;
# pragma pack(pop)

int						ft_load_warriors_into_arena(t_listhead *head);
void					ft_arena_main_loop(t_listhead lst[MAX_PLAYERS]);
void					ft_delete_proclist(t_listhead lst[MAX_PLAYERS]);
void					ft_init_process(t_listhead lst[MAX_PLAYERS]);
void					ft_fetch_instruction(t_process *process);
void					*ft_get_process(t_listhead *node);

void					op_or(t_process *p, uint32_t t[4]);
void					op_ld(t_process *p, uint32_t t[4]);
void					op_st(t_process *p, uint32_t t[4]);
void					op_add(t_process *p, uint32_t t[4]);
void					op_sub(t_process *p, uint32_t t[4]);
void					op_and(t_process *p, uint32_t t[4]);
void					op_xor(t_process *p, uint32_t t[4]);
void					op_ldi(t_process *p, uint32_t t[4]);
void					op_sti(t_process *p, uint32_t t[4]);
void					op_aff(t_process *p, uint32_t t[4]);
void					op_lld(t_process *p, uint32_t t[4]);
void					op_fork(t_process *p, uint32_t t[4]);
void					op_zjmp(t_process *p, uint32_t t[4]);
void					op_lldi(t_process *p, uint32_t t[4]);
void					op_live(t_process *p, uint32_t t[4]);
void					op_lfork(t_process *p, uint32_t t[4]);

#endif
