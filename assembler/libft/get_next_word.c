/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:12:28 by abrunet           #+#    #+#             */
/*   Updated: 2019/08/15 18:16:28 by abrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			get_next_word(char const *str, char **start, char **end)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr && ft_iswhitespace(*ptr))
		ptr++;
	*start = ptr;
	while (*ptr && !ft_iswhitespace(*ptr))
		ptr++;
	*ptr = '\0';
	*end = ptr;
	return ((int)(*end - *start));
}
