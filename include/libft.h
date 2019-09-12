/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:34:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/09/11 12:42:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>

# define BUFF_SIZE	2048

typedef struct s_listhead	t_listhead;

struct			s_listhead {
	t_listhead	*next;
	t_listhead	*prev;
};

/*
**	Strings
*/
int				ft_printable(int c);
int				ft_isdigit(int c);
int				digit_string(char *s);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_strcmp(char const *s1, char const *s2);
void			ft_dprintf(int fd, char const *fmt, ...);
void			ft_putchar(int c);
void			ft_putnstr(char const *s, uint8_t n);
size_t			ft_strlen(char const *str);
int32_t			ft_atoi32_max(char const *str);
char			*ft_strrchr(char const *str, int c);
void			ft_putstr_endl(char const *s);
void			ft_putstr_endl_free(char const *s);
void			ft_putstr(char const *s);
char			*ft_strchr(char const *s, int c);
char			*ft_strndup(char const *s, size_t n);
char			*ft_strnew(size_t n);
char			*ft_strcat(char *s1, char const *s2);
char			*ft_strdup(char const *s);
char			*ft_strsub(char const *s, size_t i, size_t n);
char			*ft_strnjoinfree(char const *s, char const *p, size_t n);
int				ft_readline(int fd, char **string, char **line);
int64_t			ft_atoi_parsing(char **string);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strncpy(char *dst, char const *src, size_t len);
char			*ft_itoa(int n);
char			*ft_strcpy(char *dst, char const *src);
int				ft_iswhitespace(char c);
int				get_next_word(char const *str, char **start, char **end);
char			**ft_strsplit(char const *s, char c);

/*
**	Memory
*/
void			ft_bzero(void *ptr, size_t size);
void			ft_memcpy(void *dst, void *src, size_t size);
void			*ft_memset(void *dst, int c, size_t size);
uint32_t		ft_endian_swap(uint32_t nb);

/*
**	Linked list
*/
void			ft_list_init_head(t_listhead *head);
void			ft_list_push(t_listhead *e, t_listhead *head);
void			ft_list_pop(t_listhead *node, void *(ptr)(t_listhead *));
void			ft_list_add(t_listhead *e, t_listhead *prev, t_listhead *next);
void			ft_list_delete(t_listhead *head, void *(*funptr)(t_listhead *));

/*
**  Misc
*/
int				ft_printf(char const *fmt, ...);
int				ft_display_file(char const *file);

#endif
