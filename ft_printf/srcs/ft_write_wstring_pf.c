/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_wstring_pf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:26:32 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:26:32 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int					ft_write_wstr_pf(t_format *p, wchar_t *str, size_t sz)
{
	if (!str)
		return (0);
	if (!sz)
		sz = ft_strlen((char *)str);
	p->printed += sz;
	return ((int)write(1, str, sz));
}
