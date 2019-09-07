/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_compiler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:33:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/07 15:29:32 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COMPILER_H
# define COREWAR_COMPILER_H

# ifdef __GNUC__
#  define __CCV (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#  if __CCV > 29600
#   define LIKELY(x)				__builtin_expect((x), 1)
#   define UNLIKELY(x)			    __builtin_expect((x), 0)
#   ifndef OFFSETOF
#    define OFFSETOF(type, member)	__builtin_offsetof(type, member)
#   endif

#  else
#   define LIKELY(x)				(x)
#   define UNLIKELY(x)		    	(x)
#  endif

# else
#  error "Your compiler does not use the C preprocessor, try using GCC"
# endif

#endif
