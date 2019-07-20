/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:23:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/20 15:19:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_PROCESS_H
# define ARENA_PROCESS_H

# include <stdint.h>

# include "list.h"
# include "op.h"

typedef struct			s_process
{
	uint16_t			pc;
	uint16_t			carry;
	uint16_t			cycle;
	t_listhead			list;
	int32_t				registers[REG_NUMBER];
}						t_process;

int						ft_arena_main_loop(t_listhead const *head);
int						ft_arena_load_warriors(t_listhead *head);
void					*ft_get_process(t_listhead *node);

#endif
