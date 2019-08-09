/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:00:41 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/09 16:09:29 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <libft.h>
#include <arena.h>
#include <arena_process.h>

void						op_live(t_process *prc, t_parameters *parameters)
{
	if (!ft_number_in_list(parameters->tab[0]))
		return ;
	ft_dprintf(STDOUT_FILENO, "Un processus");
}
