/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:34:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:10:02 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <sys/types.h>

# include "list.h"

# define ISDIGIT(x)		((x) >= '0' && (x) <= '9')

/*
**	Strings
*/
int				ft_strcmp(char const *s1, char const *s2);
char			*ft_strrchr(char const *str, int c);
size_t			ft_strlen(char const *str);
int32_t			ft_atoi32_max(char const *str);

/*
**	Memory
*/
void			ft_bzero(void *ptr, size_t size);
void			ft_memcpy(void *dst, void *src, size_t len);
void			*ft_memset(void *dst, int c, size_t size);

/*
**	Linked list
*/
void			ft_list_init_head(t_listhead *head);
void			ft_list_push(t_listhead *e, t_listhead *head);
void			ft_list_add_tail(t_listhead *e, t_listhead *head);
void			ft_list_add(t_listhead *e, t_listhead *prev, t_listhead *next);
void			ft_list_delete(t_listhead *head, void *(*funptr)(t_listhead *));

/*
**	Bits
*/
uint16_t		ft_swap_uint16(uint16_t nb) __attribute__((always_inline));
uint32_t		ft_swap_uint32(uint32_t nb) __attribute__((always_inline));

#endif /* LIBFT_H */
