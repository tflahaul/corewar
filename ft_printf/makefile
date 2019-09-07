#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 13:49:55 by thflahau          #+#    #+#              #
#    Updated: 2018/02/02 13:49:55 by thflahau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftprintf.a

SRCS	=	ft_atoi_light.c		ft_integer_length.c		ft_strcpy.c			\
			ft_iscapital.c		ft_lowerstr.c			ft_memset.c			\
			ft_nbase_length.c	ft_power.c				ft_strchr_index.c	\
			ft_strcmp.c			ft_strndup.c			ft_strjoin.c		\
			ft_strjoinfree.c	ft_strlen.c				ft_strncpy.c		\
			ft_unsigned_atoi.c	ft_unsigned_length.c	ft_write_char_pf.c	\
			ft_itoa.c			ft_handle_prefix.c		ft_strnew.c			\
			ft_itoa_base.c		printf_b.c				printf_cs.c			\
			printf_di.c			printf_f.c				printf_np.c			\
			printf_o.c			printf_parsing.c		printf_xu.c			\
			ft_strcat.c			ft_write_string_pf.c	ft_itoa_fp.c		\
			ft_printf.c			ft_write_wstring_pf.c

OBJS	=	$(SRCS:.c=.o)

SRCDIR	=	$(addprefix srcs/, $(SRCS))

HEADER	=	-I ./headers

CFLAGS	=	-Wall -Wextra -Werror -c

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(SRCDIR) $(HEADER)
	@ar -cq $@ $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.phony: $(NAME) all clean fclean re
