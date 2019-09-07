/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:41:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/07 11:24:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define CONVS				"dsciuoxpbXfnSDOU"
# define FLAGS				"#-+lhL "
# define ABS(x)				(x < 0 ? -x : x)

typedef struct				s_format
{
	char					conv;
	char					padding_char;
	int						printed;
	unsigned int			precision;
	unsigned int			flength;
	unsigned int			padding;
	char					flags[7];
}							t_format;

typedef	unsigned long long	t_ulli;
typedef unsigned int		t_uint;
typedef void				(t_funptr)(t_format *, va_list *);

size_t						ft_strlen(char const *s);
char						*ft_itoa(long long n);
char						*ft_strnew(size_t size);
char						*ft_handle_prefix(char c);
char						*ft_itoa_base(t_ulli u, int n);
char						*ft_strcpy(char *s1, char const *s2);
char						*ft_strcat(char *s1, char const *s2);
char						*ft_strndup(char const *s, size_t u);
char						*ft_strncpy(char *s1, char const *s2, size_t n);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strjoinfree(char const *s1, char *s2, char c);
void						*ft_memset(void *s, int c, size_t n);
void						ft_putnbr_base(t_format *p, t_ulli nb);
void						ft_fmt_base(t_format *p, char *s, size_t u);
void						ft_formatted_addr(t_format *p, char const *s);
void						ft_putnbr_octal(t_format *p, t_ulli u);
void						ft_putaddr_right_pf(t_format *p, char const *s);
void						ft_lowerstr(char **str);
void						ft_itoa_fp(long long n, long long d, char *s);
char						*ft_itoa_base(t_ulli n, int b);
long double					ft_power(int p, long double d);
unsigned int				ft_ulength(t_ulli n);
unsigned int				ft_unsigned_length(t_ulli u);
unsigned int				ft_integer_length(long long n);
unsigned int				ft_unsigned_atoi(char const *s);
unsigned int				ft_nbase_length(t_ulli n, char const *s);
int							ft_iscapital(int c);
int							ft_atoi_light(char const *s);
int							ft_strchr_index(char c, char *s);
int							ft_strcmp(char const *s1, char const *s2);
int							ft_printf(char const *format, ...);
int							ft_iscapital(int c);
int							ft_atoi_light(char const *s);
int							ft_strchr_index(char c, char *s);
int							ft_write_char_pf(t_format *p, int c);
int							ft_write_str(t_format *p, char const *s, size_t u);
int							ft_write_wstr_pf(t_format *p, wchar_t *s, size_t u);
int							ft_printf(char const *s, ...);
void						ft_reset_struct_datas(t_format *p);
void						ft_get_format(char const *s, t_format *p);
t_funptr					*ft_printf_dispatcher(char c);

void						ft_putpercent(t_format *p);
void						ft_putnbr_printf(t_format *p, va_list *a);
void						ft_putstr_printf(t_format *p, va_list *a);
void						ft_get_numprinted(t_format *p, va_list *a);
void						ft_putchar_printf(t_format *p, va_list *a);
void						ft_putdouble_printf(t_format *p, va_list *a);
void						ft_putbinary_printf(t_format *p, va_list *a);
void						ft_putaddress_printf(t_format *p, va_list *a);
void						ft_putnbr_base_printf(t_format *p, va_list *a);

#endif
