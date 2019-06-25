/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:33:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/25 22:07:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <stdio.h>
# include <string.h>
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

# define FILE_FORMAT		".cor"

typedef struct				s_listhead {
	struct s_listhead		*next;
	struct s_listhead		*prev;
}							t_listhead;

typedef struct				s_process {
	t_listhead				list;
	char					registers[REG_NUMBER][REG_SIZE]; // ?
	uint64_t				instruction;	// Type à définir
}							t_process;

/*
**	@id: 		Players number
**	@name: 		Players name
**	@processes:	Head of players processes list
**	@next:		Pointer to next player
**
**	List is singly linked as we dont expect to have a large amount of players.
*/
typedef struct				s_player {
	uint32_t				id;
	char					name[64];
	t_process				processes;
}							t_player;

/*
**	@options:	Bitmap used to keep track of executable's options
**	@max_cycles: Maximum amount of cycles before ending the game
*/
# pragma pack(push, 2)

typedef struct				s_arena_state {
	uint16_t				options;
	uint32_t				max_cycles;
	uint8_t					arena[MEM_SIZE];
}							t_arena_state;
# pragma pack(pop)

static t_arena_state		g_arena;

# define OPTION_DUMP		0x008000u
# define OPTION_NBR			0x004000u
# define DUMPMASK			0x3f80u
# define DUMP_SHIFT			0x7u
# define BUFF_SIZE			1024
# define EXTRACT_REG(x)		(x & 0x1fu) __deprecated
# define EXTRACT_DUMP(x)	((x & DUMPMASK) >> DUMP_SHIFT)
# define MAX_CYCLES			(10 * 1000 * 1000)
# define LIST_INIT(ptr)		{&(ptr), &(ptr)}

typedef char				t_instruction;
typedef char				t_arena_memory;

__attribute__((always_inline))
static inline void			ft_arena_init_params(void)
{
	g_arena.options = 0;
	g_arena.max_cycles = MAX_CYCLES;
}

static void					ft_dump_memory(void)
{
	register uint16_t		index;

	index = 0;
	while (++index < MEM_SIZE);
}

/*
**	Attention:
**	- Si l'id passé en paramètre est déjà donné à un autre joueur
**	Possible de donner d'abord des numéros aux joueurs avec id spécifié
**	puis donner les id libres aux autres ensuite.
*/
static inline t_player		*ft_memalloc_player(uint32_t id)
{
	t_player				*node;

	node = (t_player *)malloc(sizeof(*node));
	if (LIKELY(node != NULL))
		__builtin_memset(node, 0, sizeof(*node));
	return (node);
}

/*
**	--- LISTS ---
**
**	These are easy-to-use, highly portable functions for manipulating
**	circular linked lists. This implementation comes from the Linux
**	kernel source tree, file `include/linux/list.h`
*/
__attribute__((always_inline))
static inline void			ft_list_init_head(t_listhead *head)
{
	head->next = head;
	head->prev = head;
}

/*
**	Insert a new entry between two known consecutive entries (prev & next).
**	This is only for internal list manipulation where we know the `prev`
**	and `next` pointers.
*/
__attribute__((always_inline))
static inline void			ft_list_add(t_listhead *node,
										t_listhead *prev,
										t_listhead *next)
{
	next->prev = node;
	node->next = next;
	node->prev = prev;
	prev->next = node;
}

/*
**	Insert a new entry AFTER the specified head. This is good for
**	implementing stacks.
*/
__attribute__((always_inline))
static inline void			ft_list_push(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head, head->next);
}

__attribute__((always_inline))
static inline void			ft_list_pop(t_listhead *node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free((void *)ft_queue_entry(node));
}

/*
**	Insert a new entry BEFORE the specified head. This is good for
**	implementing queues.
*/
__attribute__((always_inline))
static inline void			ft_list_add_tail(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head->prev, head);
}

static inline int32_t		ft_valid_file_fmt(char const *file, char const *fmt)
{
	if (UNLIKELY(file == NULL))
		return (EXIT_FAILURE);
	file = file + strlen(file) - (sizeof(char) << 2);
	return (strcmp(file, fmt) ? EXIT_FAILURE : EXIT_SUCCESS);
}

static inline int			ft_extract_data_from_instruction(void)
{
	return (0);				// En fonction du format de l'instruction
}

__attribute__((always_inline))
static inline void			ft_retative_indexing(int *map, uint64_t addr)
{
	map[addr % IDX_MOD] = ft_extract_data_from_instruction();
}

#endif /* ARENA_H */
