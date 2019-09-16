/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:38:13 by abrunet           #+#    #+#             */
/*   Updated: 2019/08/15 18:50:30 by abrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline int						ft_printable(int c)
{
	return (c > 31 && c < 127);
}