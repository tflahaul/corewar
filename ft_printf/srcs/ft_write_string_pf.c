/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string_pf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:26:40 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:26:40 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int					ft_write_str(t_format *p, char const *str, size_t sz)
{
	if (!str)
		return (0);
	if (sz == 0)
		sz = ft_strlen(str);
	p->printed += sz;
	return ((int)write(1, str, sz));
}
