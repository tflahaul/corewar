/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:33:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/24 21:10:31 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <stdlib.h>
# include <stdint.h>
# include "../include/op.h"

# ifdef __GNUC__
#  define __CCV (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#  if __CCV > 29600
#   define LIKELY(x)		__builtin_expect((x), 1)
#   define UNLIKELY(x)		__builtin_expect((x), 0)

#  else
#   define LIKELY(x)		(x)
#   define UNLIKELY(x)		(x)
#  endif /* __CCV */

# else
#  error "Your compiler does not use the C preprocessor, try using GCC"
# endif /* __GNUC__ */

typedef struct			s_listhead {
	struct s_listhead	*next;
	struct s_listhead	*prev;
}						t_listhead;

typedef struct			s_process {
	t_listhead			list;
	char				registers[REG_NUMBER][REG_SIZE]; // ?
	uint64_t			instruction;	// Type à définir
}						t_process;

typedef struct			s_player {
	char				name[64];		// Players name (cannot exceed 63)
	t_process			processes;		// Players instruction list (head)
}						t_player;

/*
**	|16|15|14|...|8|7|...|1|
*/
# pragma pack(push, 2)

typedef struct			s_arena_state {
	uint16_t			options;
	uint32_t			max_cycles;
}						t_arena_state;
# pragma pack(pop)

static t_arena_state	g_arena;

# define OPTION_DUMP	0x008000u
# define OPTION_NBR		0x004000u
# define EXTRACT_REG(x)	(x & 0x1fu)
# define MAX_CYCLES		(10 * 1000 * 1000)
# define LIST_INIT(ptr)	{&(ptr), &(ptr)}
# define EXTRACTDUMP	(g_arena.options) // mask
# define BUFF_SIZE		1024

typedef char			t_instruction;
typedef char			t_arena_memory;

__attribute__((always_inline))
static inline void		ft_arena_init_params(void)
{
	g_arena.options = 0;
	g_arena.max_cycles = MAX_CYCLES;
}

__attribute__((always_inline))
static inline void		ft_list_init_head(t_listhead *head)
{
	head->next = head;
	head->prev = head;
}

static inline int		ft_extract_data_from_instruction(void)
{
	return (0);						// En fonction du format de l'instruction
}

__attribute__((always_inline))
static inline void		ft_retative_indexing(int *map, uint64_t addr)
{
	map[addr % IDX_MOD] = ft_extract_data_from_instruction();
}

#endif /* ARENA_H */
