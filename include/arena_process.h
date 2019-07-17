/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:23:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 16:45:20 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_PROCESS_H
# define ARENA_PROCESS_H

# include <stdint.h>
# include <list_torvalds.h>

# pragma pack(push, 4)

/*
**	@id:	Id du joueur propriétaire
**	@pc:	Compteur ordinal (program counter)
*/
typedef struct				s_process
{
	int32_t					id;
	uint16_t				pc;
	t_listhead				list;
}							t_process;
# pragma pack(pop)

#define GET_PROCESS(ptr)	((t_process *)(ptr - offsetof(t_process, list)))

int							ft_arena_load_warriors(t_listhead *head);

#endif
