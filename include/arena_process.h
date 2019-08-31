/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:23:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/31 15:50:29 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_PROCESS_H
# define ARENA_PROCESS_H

# include <stdint.h>

# include "libft.h"
# include "op.h"

# pragma pack(push, 2)

typedef struct s_process		t_process;

typedef struct			s_instructions {
	void				(*funptr)(t_process *, t_parameters *);
	unsigned int		carry;
	unsigned int		cycle;
	unsigned int		has_code_byte;
	unsigned int		dirsize;
	unsigned int		readmem;
}						t_ops;
# pragma pack(pop)

/*
**	@registers:		Registres du processus. On en ajoute 1 pour ne pas
**					avoir à décrémenter le numéro de registre à chaque
**					appel (le registre 6 est à l'index 6). Le registre
**					0 est utilisé pour stocker la valeur du carry.
**	@live:			Nombre de live valides sur la période.
**	@pc:			Program counter
*/
typedef struct			s_process {
	t_listhead			list;
	t_parameters		params;
	t_ops				instruction;
	int32_t				registers[REG_NUMBER + 1];
	uint32_t			live;
	int16_t				pc;
}						t_process;

# define RESET_PROCESS(x)	(((t_process *)x)->instruction.funptr = (void *)0)

int					ft_load_warriors_into_arena(t_listhead *head);
void				ft_arena_main_loop(t_listhead *list);
void				ft_for_each_process(t_listhead *list);
void				ft_init_process_list(t_listhead *list);
void				ft_delete_process_list(t_listhead *list);
void				ft_fetch_instruction(t_process *process, t_parameters *p);
void				*ft_get_process(t_listhead *node);

/*
**	Instructions
*/
void				op_or(t_process *p, t_parameters *);
void				op_ld(t_process *p, t_parameters *);
void				op_st(t_process *p, t_parameters *);
void				op_add(t_process *p, t_parameters *);
void				op_sub(t_process *p, t_parameters *);
void				op_and(t_process *p, t_parameters *);
void				op_xor(t_process *p, t_parameters *);
void				op_ldi(t_process *p, t_parameters *);
void				op_sti(t_process *p, t_parameters *);
void				op_aff(t_process *p, t_parameters *);
void				op_lld(t_process *p, t_parameters *);
void				op_fork(t_process *p, t_parameters *);
void				op_zjmp(t_process *p, t_parameters *);
void				op_lldi(t_process *p, t_parameters *);
void				op_live(t_process *p, t_parameters *);
void				op_lfork(t_process *p, t_parameters *);

#endif
