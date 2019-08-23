/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:02:04 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/22 16:09:44 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

size_t					ft_list_size(t_listhead const *head)
{
	size_t				size;
	t_listhead			*position;

	size = 0;
	position = (t_listhead *)head;
	if (__builtin_expect((head == NULL), 0))
		return (0);
	while ((position = position->next) != head)
		++size;
	return (size);
}
