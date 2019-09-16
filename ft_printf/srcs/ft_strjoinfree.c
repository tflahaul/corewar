/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:25:35 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:25:35 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

char					*ft_strjoinfree(char const *s1, char *s2, char c)
{
	char				*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = ft_strjoin(s1, s2)))
		return (NULL);
	if (c == 'L' && s1 != NULL)
		free((void *)s1);
	else if (c == 'R' && s2 != NULL)
		free((void *)s2);
	else if (c == 'B' && s1 != NULL && s2 != NULL)
	{
		free((void *)s1);
		free((void *)s2);
	}
	return (ptr);
}
