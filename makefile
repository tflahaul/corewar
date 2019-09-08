# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 11:46:49 by thflahau          #+#    #+#              #
#    Updated: 2019/09/08 11:52:45 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	=	corewar
NAME2	=	asm

CORDIR	=	arena
ASMDIR	=	assembler

all: $(NAME1) $(NAME2)

$(LIBFT):
	@make -C libft

$(PRINTF):
	@make -C ft_printf

$(NAME1): $(LIBFT) $(PRINTF)
	@make -C $(CORDIR)

$(NAME2): $(LIBFT) $(PRINTF)
	@make -C $(ASMDIR)

clean:
	@make clean -C $(CORDIR)
	@make clean -C $(ASMDIR)

fclean:
	@make fclean -C $(CORDIR)
	@make fclean -C $(ASMDIR)

re:
	@make re -C $(CORDIR)
	@make re -C $(ASMDIR)
