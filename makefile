# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 10:11:18 by thflahau          #+#    #+#              #
#    Updated: 2019/07/14 09:40:27 by thflahau         ###   ########.fr        #
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
				-Werror

INCFLAG		=	-I $(HDR)
LIBFLAG		=	-L $(LIBDIR) -lft

#########   SOURCES   #########
include $(ARENADIR)/arena_srcs.mk
include $(ASMDIR)/assembler_srcs.mk

HDRFILES	=	$(filter %.h, $(shell find $(HDR)))
LIBFT		=	$(LIBDIR)/libft.a

all		:
	@make -C $(LIBDIR)
	@gcc $(CFLAGS) arena/*.c share/*.c $(INCFLAG) $(LIBFLAG) -o $(NAME_ARENA)

clean	:
	@make clean -C $(LIBDIR)

fclean	:
	@make fclean -C $(LIBDIR)
	@/bin/rm $(NAME_ARENA)

re		: fclean all
