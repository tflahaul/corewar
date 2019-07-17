/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:33:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 16:15:33 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "op.h"

# include <stdint.h>

# define FILE_FORMAT		".cor"

typedef struct				s_warrior {
	int32_t					id;
	uint32_t				size;
	uint8_t					program[CHAMP_MAX_SIZE];
	char					name[PROG_NAME_LENGTH + 1];
	char					comment[COMMENT_LENGTH + 1];
	struct s_warrior		*next;
}							t_warrior;

/*
**	@options:		Bitmap used to keep track of given options
**	@dump_cycles:	Amount of cycles before dumping the memory on the stdin
**	@warriors:		Head of warriors singly linked list
*/
typedef struct				s_arena_state {
	int32_t					value;
	int32_t					dump_cycles;
	t_warrior				*warriors;
	uint8_t					arena[MEM_SIZE];
	uint16_t				options;
}							t_arena_state;

t_arena_state				g_arena;

# define OPTION_N			0x00000001
# define OPTION_V			0x00000010

# define HAS_NUMBER(x)		(x & OPTION_N)
# define UNSET_OPTION_N(x)	(x &= ~OPTION_N)

int							ft_malloc_new_warrior(void);
int							ft_parse_args(int argc, char const **argv);
int							ft_parse_warrior(char const *file);
int							ft_fetch_and_check_metadata(int fd);
int							ft_number_in_list(int32_t id);
void						ft_hexdump_memory(void);
unsigned int				ft_list_size_warrior(void);

#endif /* ARENA_H */
