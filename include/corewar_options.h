/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_options.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 08:40:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/28 12:33:57 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_OPTIONS_H
# define COREWAR_OPTIONS_H

enum					e_needargs {
	no_argument,
	required_argument
};

/*
**	@longname:	Long name for multi-letter options preceded by double dash
**	@funptr:	Function pointer to corresponding option function
**	@has_arg:	Flag to know if the option takes an argument
**	@shortname:	Character for single-letter options preceded by single dash
*/
typedef struct			s_options {
	char				*longname;
	void				(*funptr)(char const **av);
	int					has_arg;
	int					shortname;
}						t_options;

void					ft_get_dump(char const **av);
void					ft_get_numb(char const **av);
void					ft_print_help(char const **av);
void					ft_set_visualize(char const **av);

void					ft_get_options(char const ***av);

#endif
