/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunet <abrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:58:49 by abrunet           #+#    #+#             */
/*   Updated: 2019/08/15 16:41:48 by abrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <asm_errors.h>

void				ft_print_asm_usage(void)
{
	ft_dprintf(1, "usage: ./asm <file.s>\n");
}

int					ft_puterror(char const *string)
{
	if (string != NULL)
		ft_dprintf(1, "asm: %s\n", string);
	else
		ft_dprintf(1, "%s\n", HELPMSG);
	return (EXIT_ERROR);
}
