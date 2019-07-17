/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:35:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 18:16:09 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_errors.h>
#include <arena_memory.h>
#include <arena_process.h>
#include <corewar_compiler.h>

/* DEBUG */
#include <stdio.h>
static inline t_warrior	*getwar(int id)
{
	t_warrior			*node = g_arena.warriors;

	while (node != NULL && node->id != id)
		node = node->next;
	return (node);
}

/* DEBUG */
static void				ft_print_pcs(t_listhead const *head)
{
	register uint16_t	index = 0;

	while (index < MEM_SIZE)
	{
		t_listhead *position = (t_listhead *)head;
		while ((position = position->next) != head)
			if ((GET_PROC(position))->pc == index)
				printf("PC = [%02hhx]\n", g_arena.arena[index]);
		++index;
	}
	for (t_listhead *p = (t_listhead *)head->next; p != head; p = p->next)
		printf("[%s] -> PC = %hu\n", (getwar(GET_PROC(p)->registers[0]))->name, GET_PROC(p)->pc);
}

int						main(int argc, char const **argv)
{
	t_listhead			head;

	if (__unlikely(ft_parse_args(argc, argv) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	ft_list_init_head(&head);
	if (ft_arena_load_warriors(&head) != EXIT_SUCCESS)
		return (EXIT_ERROR);
	if (g_arena.options & OPTION_V)
		ft_hexdump_memory();
	ft_print_pcs(&head);
	ft_list_del(&head);
	return (EXIT_SUCCESS);
}
