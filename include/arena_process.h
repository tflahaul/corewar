/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:23:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 17:50:47 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_PROCESS_H
# define ARENA_PROCESS_H

# include <stdint.h>
# include <list_torvalds.h>

typedef struct				s_process
{
	uint16_t				pc;
	uint16_t				carry;
	t_listhead				list;
	int32_t					registers[REG_NUMBER];
}							t_process;

#define GET_PROC(ptr)	((t_process *)((char *)ptr - offsetof(t_process, list)))

int							ft_arena_load_warriors(t_listhead *head);

#endif
