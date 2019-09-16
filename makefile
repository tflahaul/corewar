# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 22:08:10 by abrunet           #+#    #+#              #
#    Updated: 2019/09/11 12:24:14 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME1		= 	corewar
NAME2		=	asm

#######   DIRECTORIES   #######
HDR			=	include
LIBDIR		=	libft
PRTFDIR		=	ft_printf
ARENADIR	=	arena
ASSEMDIR	=	assembler
OBJDIR		=	obj

DIRS := $(patsubst $(ARENADIR)%, $(OBJDIR)%, $(shell find $(ARENADIR) -type d))
DIRAS := $(patsubst $(ASSEMDIR)%, $(OBJDIR)%, $(shell find $(ASSEMDIR) -type d))

##########   FLAGS   ##########
CFLAGS		=	-Wall						\
				-Wextra						\
				-Werror						\
				-Wshadow					\
				-Wnull-dereference			\
				-pedantic

INCFLAG		=	-I $(HDR)
LIBFLAG		=	-L $(LIBDIR) -lft -L $(PRTFDIR) -lftprintf

#########   SOURCES   #########
LIBFT		=	$(LIBDIR)/libft.a

SRCSARE		=	$(shell find $(ARENADIR) -type f -name "*.c")
SRCSASM		=	$(shell find $(ASSEMDIR) -type f -name "*.c")

ARENA_OBJ	=	$(patsubst $(ARENADIR)%.c, $(OBJDIR)%.o, $(SRCSARE))
ASM_OBJ		=	$(patsubst $(ASSEMDIR)%.c, $(OBJDIR)%.o, $(SRCSASM))

DEPENDS		=	${ARENA_OBJ:.o=.d}
DEPENDSASM	=	${ASM_OBJ:.o=.d}

#########   COLORS   ##########
STD			=	\033[0m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

##########   RULES   ##########
all			: $(NAME1) $(NAME2)

$(NAME1)	: $(ARENA_OBJ)
	@make -C $(LIBDIR)
	@make -C $(PRTFDIR)
	@printf "$(YELLOW)%-55s$(STD)" "Building executable $@ ..."
	@$(CC) $(CFLAGS) $(INCFLAG) $(ARENA_OBJ) -o $@ $(LIBFLAG)
	@echo "$(GREEN)DONE$(STD)"

-include $(DEPENDS)

$(OBJDIR)/%.o: $(ARENADIR)/%.c
	@mkdir -p $(DIRS)
	@printf "%-55s" " > Compiling $* ..."
	@$(CC) $(CFLAGS) -MMD $(INCFLAG) -c $< -o $@
	@echo '✓'

$(NAME2)	: $(ASM_OBJ)
	@make -C $(LIBDIR)
	@make -C $(PRTFDIR)
	@printf "$(YELLOW)%-55s$(STD)" "Building executable $@ ..."
	@$(CC) $(CFLAGS) $(INCFLAG) $(ASM_OBJ) -o $@ $(LIBFLAG)
	@echo "$(GREEN)DONE$(STD)"

-include $(DEPENDSASM)

$(OBJDIR)/%.o: $(ASSEMDIR)/%.c
	@mkdir -p $(DIRAS)
	@printf "%-55s" " > Compiling $* ..."
	@$(CC) $(CFLAGS) -MMD $(INCFLAG) -c $< -o $@
	@echo '✓'

clean		:
	@/bin/rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)
	@make clean -C $(PRTFDIR)

fclean		: clean
	@/bin/rm -rf $(NAME1)
	@/bin/rm -rf $(NAME2)
	@make fclean -C $(LIBDIR)
	@make fclean -C $(PRTFDIR)

re			: fclean all

.PHONY		: all $(LIBFT) clean fclean re
