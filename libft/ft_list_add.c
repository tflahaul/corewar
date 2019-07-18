/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:07:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:05:51 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void		ft_list_add(t_listhead *node, t_listhead *prev, t_listhead *next)
{
	next->prev = node;
	node->next = next;
	node->prev = prev;
	prev->next = node;
}
