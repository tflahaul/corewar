# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 11:46:49 by thflahau          #+#    #+#              #
#    Updated: 2019/09/11 13:02:48 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	=	corewar
NAME2	=	asm

CORDIR	=	arena
ASMDIR	=	assembler

all: $(LIBFT) $(PRINTF) $(NAME1) $(NAME2)

$(LIBFT):
	@make -C libft

$(PRINTF):
	@make -C ft_printf

$(NAME1):
	@make -C libft
	@make -C ft_printf
	@make -C $(CORDIR)

$(NAME2):
	@make -C libft
	@make -C ft_printf
	@make -C $(ASMDIR)

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@make clean -C $(CORDIR)
	@make clean -C $(ASMDIR)

fclean: clean
	@make fclean -C $(CORDIR)
	@make fclean -C $(ASMDIR)

re: fclean all

.PHONY: all clean fclean re
