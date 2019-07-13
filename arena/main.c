/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/13 11:54:39 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <arena.h>
#include <arena_errors.h>
#include <arena_memory.h>
#include <corewar_compiler.h>

static void				ft_print_warriors(void)
{
	t_warrior			*temp = g_arena.warriors;

	while (temp != NULL)
	{
		printf("===---====-----====------==-=-=-=-=\n");
		printf("Name:[%s]\n", temp->name);
		printf("Comment:[%s]\n", temp->comment);
		printf("Size:[%u]\n", temp->size);
		printf("ID:[%i]\n", temp->id);
		printf("Code:");
		for (unsigned int i = 0; i < temp->size; ++i)
		{
			if (!(i % 32))
				printf("\n");
			printf("%02x ", temp->program[i]);
		}
		printf("\n");
		temp = temp->next;
	}
}

int						main(int argc, char const **argv)
{
	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	ft_print_warriors();
	return (EXIT_SUCCESS);
}
