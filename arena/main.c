/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/11 14:53:50 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <arena.h>
#include <arena_errors.h>
#include <arena_memory.h>
#include <corewar_compiler.h>

static inline void		ft_print_warriors(void)
{
	t_warrior			*temp = g_arena.warriors;

	while (temp != NULL)
	{
		printf("===---====-----====------==-=-=-=-=\n");
		printf("Name:[%s]\n", temp->name);
		printf("Comment:[%s]\n", temp->comment);
		printf("Size:[%u]\n", temp->size);
		printf("ID:[%i]\n", temp->id);
		temp = temp->next;
	}
}

int						main(int argc, char const **argv)
{
	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (ft_free_warriors(EXIT_FAILURE));
	ft_print_warriors();
	return (EXIT_SUCCESS);
}
