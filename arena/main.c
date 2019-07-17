/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 16:55:53 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <arena.h>
#include <arena_errors.h>
#include <arena_memory.h>
#include <arena_process.h>
#include <corewar_compiler.h>

/* DEBUG */
static inline int		ft_find_in_list(t_listhead const *head, uint16_t index)
{
	t_listhead			*position;

	position = (t_listhead *)head;
	while ((position = position->next) != head)
		if ((GET_PROCESS(position))->pc == index)
			return (1);
	return (0);
}

/* DEBUG */
static void				ft_print_pcs(t_listhead const *head)
{
	register uint16_t	index = 0;

	while (index < MEM_SIZE)
	{
		if (ft_find_in_list(head, index))
			printf("\nPC = [%02hhx]\n", g_arena.arena[index]);
		++index;
	}
	int size = 0;
	for (t_listhead *ptr = (t_listhead *)head->next; ptr != head; ptr = ptr->next)
	{
		printf("Process at PC %hu\n", GET_PROCESS(ptr)->pc);
		++size;
	}
	printf("SIZE = [%i]\n", size);
}

int						main(int argc, char const **argv)
{
	t_listhead			head;

	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	ft_list_init_head(&head);
	ft_arena_load_warriors(&head);
	if (g_arena.options & OPTION_V)
		ft_hexdump_memory();
	ft_print_pcs(&head);
	return (EXIT_SUCCESS);
}
