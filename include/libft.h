/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:34:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/12 13:16:26 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>

# define ISDIGIT(x)		((x) >= '0' && (x) <= '9')

/*
**	Strings
*/
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_fast_strrchr(char const *str, int c);
size_t				ft_fast_strlen(char const *str);
int32_t				ft_atoi_max_int32(char const *str);

/*
**	Bits
*/
uint16_t			ft_swap_uint16(uint16_t nb) __attribute__((always_inline));
uint32_t			ft_swap_uint32(uint32_t nb) __attribute__((always_inline));

#endif /* LIBFT_H */