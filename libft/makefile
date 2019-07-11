# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 10:35:03 by thflahau          #+#    #+#              #
#    Updated: 2019/07/11 12:06:33 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME		=	libft.a

INCLUDE		=	../include

CFLAGS		=	-Wall				\
				-Wextra				\
				-Werror				\
				-msse4				\
				-O3					\
				-c

HFLAGS		=	-I $(INCLUDE)

include		libftsources.mk

OBJS		=	$(LIBSOURCES:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	@$(CC) $(HFLAGS) $(CFLAGS) $(LIBSOURCES)
	@ar -cq $@ $(OBJS)
	@ranlib $@

%.o		: %.c	$(INCLUDE)/libft.h
	@$(CC) $(CFLAGS) $(HFLAGS) -o $@ -c $<

clean	:
	@/bin/rm -f $(OBJS)

fclean	: clean
	@/bin/rm -f $(NAME)

re		: fclean all

.phony	: $(NAME) clean fclean re
