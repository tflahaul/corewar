/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:33:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 14:33:06 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "op.h"

# include <stdint.h>

# define FILE_FORMAT		".cor"

typedef struct				s_listhead {
	struct s_listhead		*next;
	struct s_listhead		*prev;
}							t_listhead;

typedef struct				s_warrior {
	int32_t					id;
	uint32_t				size;
	uint8_t					program[CHAMP_MAX_SIZE];
	char					name[PROG_NAME_LENGTH + 1];
	char					comment[COMMENT_LENGTH + 1];
	struct s_warrior		*next;
}							t_warrior;

/*
**	@option:		Integer used to store `-n' option value
**	@dump_cycles:	Amount of cycles before dumping the memory on the stdin
**	@warriors:		Head of warriors singly linked list
*/
typedef struct				s_arena_state {
	int32_t					option;
	int32_t					dump_cycles;
	t_warrior				*warriors;
}							t_arena_state;

t_arena_state				g_arena;

int							ft_malloc_new_warrior(void);
int							ft_parse_args(int argc, char const **argv);
int							ft_parse_warrior(char const *file);
int							ft_fetch_and_check_metadata(int fd);

#endif /* ARENA_H */
