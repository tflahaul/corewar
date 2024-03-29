/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:24:22 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/12 13:14:49 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int						ft_strcmp(char const *s1, char const *s2)
{
	if (__builtin_expect((s1 == s2), 0))
		return (0);
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (*(s1 - 1) - *(s2 - 1));
	return ((*s1) - (*s2));
}
