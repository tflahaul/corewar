/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:23:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:09:35 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_PROCESS_H
# define ARENA_PROCESS_H

# include <stdint.h>

# include "list.h"
# include "op.h"

typedef struct				s_process
{
	uint16_t				pc;
	uint16_t				carry;
	t_listhead				list;
	int32_t					registers[REG_NUMBER];
}							t_process;

void						*ft_get_process(t_listhead *node);
int							ft_arena_load_warriors(t_listhead *head);

#endif
