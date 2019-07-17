/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_torvalds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:29:58 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 16:28:40 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list_torvalds.h>

inline void				ft_list_init_head(t_listhead *head)
{
	head->next = head;
	head->prev = head;
}

inline void				ft_list_add(t_listhead *node,
									t_listhead *prev,
									t_listhead *next)
{
	next->prev = node;
	node->next = next;
	node->prev = prev;
	prev->next = node;
}

inline void				ft_list_push(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head, head->next);
}

inline void				ft_list_add_tail(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head->prev, head);
}
