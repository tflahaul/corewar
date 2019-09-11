/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:54:11 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/15 18:36:32 by abrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline int						ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}