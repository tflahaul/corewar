/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:33:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/28 13:22:09 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <stdint.h>
# include "op.h"

# define FILE_FORMAT	".cor"

# pragma pack(push, 2)

typedef struct			s_warrior {
	int32_t				id;
	uint32_t			size;
	struct s_warrior	*next;
	uint8_t				program[CHAMP_MAX_SIZE];
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
}						t_warrior;
# pragma pack(pop)

/*
**	@options:		Bitmap used to keep track of given options
**	@dump_cycles:	Amount of cycles before dumping the memory on the stdin
**	@warriors:		Head of warriors singly linked list
*/
typedef struct			s_arena_state {
	t_warrior			*warriors;
	t_warrior			*last_alive;
	int32_t				value;
	int32_t				dump_cycles;
	uint8_t				arena[MEM_SIZE];
	uint32_t			options;
	uint32_t			size;
}						t_arena_state;

t_arena_state			g_arena;

# define OPTION_N		0x00000001ul
# define OPTION_V		0x00000010ul
# define OPTION_D		0x00000100ul
# define OPTION_P		0x00001000ul

# define ABS(x)				((x) < 0 ? -(x) : (x))

# define HAS_VISU(x)		(x & OPTION_V)
# define HAS_DUMP(x)		(x & OPTION_D)
# define HAS_NUMBER(x)		(x & OPTION_N)
# define UNSET_OPTION_N(x)	(x &= ~OPTION_N)
# define ISREG(x)			((x) > 0 && (x) < 17)
# define BINARR_TO_I(x)		((x[0] << 24) | (x[1] << 16) | (x[2] << 8) | (x[3]))

# define MEMINDEX(x)	((x) % MEM_SIZE)
# define NEG_IDX(x)		((x) < 0 ? -(ABS(x) % IDX_MOD) : (x) % IDX_MOD)
# define NEG_MEM(x)		((x) < 0 ? (MEM_SIZE + MEMINDEX(x)) : MEMINDEX(x))

/*
**	Parsing
*/
int						ft_malloc_new_warrior(void);
int						ft_parse_args(int argc, char const **argv);
int						ft_parse_warrior(char const *file);
int						ft_fetch_and_check_metadata(int fd);
int						ft_number_in_list(int32_t id);
void					ft_scan_warriors_id(void);
void					ft_hexdump_memory(void);
unsigned int			ft_list_size_warrior(void);
t_warrior				*ft_get_warrior_from_id(int id);

/*
**	Conversion
*/
void					ft_int_to_binarray(int ptr, int nb);
int32_t					ft_binarray_to_int(int ptr, int sz);

/*
**	Memory
*/
void					ft_free_warriors(void) __attribute__((destructor));
unsigned short			ft_safe_update_pc(int16_t pc, int16_t ptr);

#endif
