# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 10:35:03 by thflahau          #+#    #+#              #
#    Updated: 2019/08/28 15:33:48 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME		=	libft.a

INCLUDE		=	../include

CFLAGS		=	-Wall				\
				-Wextra				\
				-Werror				\
				-Wno-unused-result	\
				-msse4				\
				-O3					\
				-c

HFLAGS		=	-I $(INCLUDE)

include		libftsources.mk

OBJS		=	$(LIBSOURCES:.c=.o)

STD			=	\033[0m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

all		: $(NAME)

$(NAME)	: $(OBJS)
	@printf "$(YELLOW)%-40s$(STD)" "Building library $@ ..."
	@$(CC) $(HFLAGS) $(CFLAGS) $(LIBSOURCES)
	@ar -cq $@ $(OBJS)
	@ranlib $@
	@echo "$(GREEN)DONE$(STD)"

%.o		: %.c	$(INCLUDE)/libft.h
	@printf "%-43s" " > Compiling libft/$* ..."
	@$(CC) $(CFLAGS) $(HFLAGS) -o $@ -c $<
	@echo '✓'

clean	:
	@/bin/rm -f $(OBJS)

fclean	: clean
	@/bin/rm -f $(NAME)

re		: fclean all

.phony	: $(NAME) clean fclean re
