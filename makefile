# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 22:08:10 by abrunet           #+#    #+#              #
#    Updated: 2019/07/29 11:16:40 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME1		= 	corewar
NAME2		=	asm

#######   DIRECTORIES   #######
HDR			=	include
LIBDIR		=	libft
ARENADIR	=	arena
ASMDIR		=	assembler
OBJDIR		=	obj

##########   FLAGS   ##########
CFLAGS		=	-Wall						\
				-Wextra						\
				-Werror						\
				-pedantic

INCFLAG		=	-I $(HDR)
LIBFLAG		=	-L $(LIBDIR) -lft

#########   SOURCES   #########
include $(ARENADIR)/arena_srcs.mk
include $(ASMDIR)/assembler_srcs.mk

LIBFT		=	$(LIBDIR)/libft.a

SRCS		=	$(addprefix $(ARENADIR)/, $(ARENA_SRCS))

ARENA_OBJ	=	$(patsubst %,$(OBJDIR)/%.o, $(ARENA_SRCS))

DEPENDS		=	${ARENA_OBJ:.o=.d}

#########   COLORS   ##########
STD			=	\033[0m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

##########   RULES   ##########
all				: $(LIBFT) $(NAME1)

$(NAME1)		: $(ARENA_OBJ)
	@printf "$(YELLOW)%-40s$(STD)" "Building executable $@ ..."
	@$(CC) $(CFLAGS) $(INCFLAG) share/errors.c $(ARENA_OBJ) -o $@ $(LIBFLAG)
	@echo "$(GREEN)DONE$(STD)"

$(LIBFT)		: $(HDR)/libft.h
	@make -C $(LIBDIR)

-include $(DEPENDS)

$(OBJDIR)/%.o	: $(ARENADIR)/%.c
	@mkdir -p $(OBJDIR)
	@printf "%-40s" " > Compiling $* ..."
	@$(CC) $(CFLAGS) -MMD $(INCFLAG) -c $< -o $@
	@echo '✓'

clean			:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf corewar.d
	@make clean -C $(LIBDIR)

fclean			: clean
	@/bin/rm -rf $(NAME1)
	@make fclean -C $(LIBDIR)

re				: fclean all

.PHONY			: all $(LIBFT) clean fclean re
