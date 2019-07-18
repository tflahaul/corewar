# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 10:11:18 by thflahau          #+#    #+#              #
#    Updated: 2019/07/18 13:15:43 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ARENA	=	corewar
NAME_ASM	=	asm

#######   DIRECTORIES   #######
ARENADIR	=	arena
ASMDIR		=	assembler
HDR			=	include
LIBDIR		=	libft
OBJDIR		=	obj

##########   FLAGS   ##########
CFLAGS		=	-Wall					\
				-Wextra					\
				-Werror					\
				-pedantic

INCFLAG		=	-I $(HDR)
LIBFLAG		=	-L $(LIBDIR) -lft

#########   SOURCES   #########
include $(ARENADIR)/arena_srcs.mk
include $(ASMDIR)/assembler_srcs.mk

SRCS1		=	$(addprefix $(ARENADIR)/, $(ARENA_SRCS))

SHARESRC	=	share/errors.c

HDRFILES	=	$(filter %.h, $(shell find $(HDR)))
LIBFT		=	$(LIBDIR)/libft.a

all		: $(NAME_ARENA)

$(NAME_ARENA):
	@make -C $(LIBDIR)
	@gcc $(CFLAGS) $(SRCS1) $(SHARESRC) $(INCFLAG) $(LIBFLAG) -o $(NAME_ARENA)

clean	:
	@make clean -C $(LIBDIR)

fclean	:
	@make fclean -C $(LIBDIR)
	@/bin/rm $(NAME_ARENA)

re		: fclean all
