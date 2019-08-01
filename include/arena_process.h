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

int						ft_arena_load_warriors(t_listhead *head);
void					ft_decode_instruction(t_process *process);
void					ft_arena_main_loop(t_listhead const *head);
void					*ft_get_process(t_listhead *node);

#endif
