/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_tail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:09:34 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/18 15:05:55 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <list.h>

void				ft_list_add_tail(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head->prev, head);
}