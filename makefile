# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roduquen <roduquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 22:08:10 by abrunet           #+#    #+#              #
#    Updated: 2019/08/27 17:42:22 by roduquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME		= 	corewar

#######   DIRECTORIES   #######
HDR			=	include
LIBDIR		=	libft
SRCDIR		=	arena
GUIDIR		=	gui
LIBSDL		=	`sdl2-config --libs --cflags` -lSDL2 -lSDL2_ttf
OBJDIR		=	obj

DIRS := $(patsubst $(SRCDIR)%, $(OBJDIR)%, $(shell find $(SRCDIR) -type d))

##########   FLAGS   ##########
CFLAGS		=	-Wall						\
				-Wextra						\
				-Werror						\
				-Wshadow					\
				-Wnull-dereference			\
				-pedantic					\
				-g -O0 # debug

INCFLAG		=	-I $(HDR)
LIBFLAG		=	-L $(LIBDIR) -lft

#########   SOURCES   #########
LIBFT		=	$(LIBDIR)/libft.a

SRCS		=	$(shell find $(SRCDIR) -type f -name "*.c")

ARENA_OBJ	=	$(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

DEPENDS		=	${ARENA_OBJ:.o=.d}

#########   COLORS   ##########
STD			=	\033[0m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

##########   RULES   ##########
all				: $(LIBFT) $(NAME)

$(NAME)			: $(ARENA_OBJ)
	@printf "$(YELLOW)%-40s$(STD)" "Building executable $@ ..."
	@$(CC) $(CFLAGS) $(INCFLAG) $(ARENA_OBJ) -o $@ $(LIBFLAG) $(LIBSDL)
	@echo "$(GREEN)DONE$(STD)"

$(LIBFT)		: $(HDR)/libft.h
	@make -C $(LIBDIR)

-include $(DEPENDS)

$(OBJDIR)/%.o	: $(SRCDIR)/%.c
	@mkdir -p $(DIRS)
	@printf "%-43s" " > Compiling $* ..."
	@$(CC) $(CFLAGS) -MMD $(INCFLAG) -c $< -o $@ $(LIBSDL)
	@echo '✓'

clean			:
	@/bin/rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)

fclean			: clean
	@/bin/rm -rf $(NAME)
	@make fclean -C $(LIBDIR)

re				: fclean all

.PHONY			: all $(LIBFT) clean fclean re
