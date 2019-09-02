CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCDIR = ./srcs/
INCLDIR = ./includes/
SRCS = $(SRCDIR)ft_printf.c \
	   $(SRCDIR)calcul.c \
	   $(SRCDIR)parser.c \
	   $(SRCDIR)add_cs_to_buffer.c \
	   $(SRCDIR)add_d_to_buffer.c \
	   $(SRCDIR)add_f_to_buffer.c \
	   $(SRCDIR)add_o_to_buffer.c \
	   $(SRCDIR)add_p_to_buffer.c \
	   $(SRCDIR)add_u_to_buffer.c \
	   $(SRCDIR)add_x_to_buffer.c \
	   $(SRCDIR)add_xmaj_to_buffer.c \
	   $(SRCDIR)add_percent_to_buff.c \
	   $(SRCDIR)adjust_str.c \
	   $(SRCDIR)ft_affichage.c \
	   $(SRCDIR)infinity.c \
	   $(SRCDIR)infinity_add.c \
	   $(SRCDIR)send_to_buffer.c \
	   $(SRCDIR)ultimate_double_calculator.c \
	   $(SRCDIR)utilitys.c \
	   $(SRCDIR)utilitys2.c
OBJS_ = $(SRCS:.c=.o)
OBJS = $(notdir $(OBJS_))

STD			=	\033[0m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

all : $(NAME)

$(NAME) : $(SRCS)
	@make objects
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

objects : $(OBJS)

%.o : $(SRCDIR)%.c
	@printf "%-55s" " > Compiling ft_printf/$* ..."
	@$(CC) $(CFLAGS) -c -I $(INCLDIR) $^
	@echo '✓'

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all objects clean fclean re
