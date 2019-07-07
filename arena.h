/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:33:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/07 15:29:32 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "op.h"
# include <stdint.h>

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

typedef struct				s_player {
	uint32_t				id;
	uint8_t					program[CHAMP_MAX_SIZE];
	char					name[PROG_NAME_LENGTH + 2];
	struct s_player			*next;
}							t_player;

/*
**	@options:		Bitmap used to keep track of executable's options
**	@dump_cycles:	Amount of cycles before dumping the memory on the stdin
*/
typedef struct				s_arena_state {
	uint32_t				options;
	t_player				players;
	int32_t					dump_cycles;
}							t_arena_state;

static t_arena_state		g_arena;

#endif /* ARENA_H */
