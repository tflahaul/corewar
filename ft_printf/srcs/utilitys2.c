/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitys2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:47:42 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/12 16:46:27 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void		ft_memmove(char *dest, const char *src, int n)
{
	while (n > 0)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}
}

void		free_time(t_dconv *var)
{
	free(var->str);
	free(var);
}
