/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_torvalds.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:30:56 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/17 18:13:57 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TORVALDS_H
# define LIST_TORVALDS_H

typedef struct			s_listhead {
	struct s_listhead	*next;
	struct s_listhead	*prev;
}						t_listhead;

void					ft_list_init_head(t_listhead *head);
void					ft_list_push(t_listhead *e, t_listhead *head);
void					ft_list_add_tail(t_listhead *e, t_listhead *head);
void					ft_list_add(t_listhead *e, t_listhead *prev,
									t_listhead *next);

int						ft_list_del(t_listhead *head);
int						ft_puterror_memalloc_failure(t_listhead *head);

#endif
