# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/16 13:24:09 by jde-la-m     #+#   ##    ##    #+#        #
#    Updated: 2018/11/27 18:22:53 by jde-la-m    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=		libft.a

CC 			=		gcc
CFLAGS		+= 		-Wall -Wextra -Werror

SRCDIR		=		./
SRCFILE		=		ft_bzero.c		\
					ft_memalloc.c	\
					ft_memdel.c		\
					ft_memset.c		\
					ft_putchar.c	\
					ft_putendl.c	\
					ft_putstr.c		\
					ft_strncpy.c	\
					ft_strndup.c	\
					ft_strnew.c	

OBJDIR		=		./objs/
OBJ			=		$(addprefix $(OBJDIR),$(SRCFILE:.c=.o))

INCDIR		=		./
INC			=		$(addprefix -I,$(INCDIR))

RM			=		/bin/rm

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCDIR)libft.h
	@mkdir -p $(OBJDIR)
	@printf "."
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n|-> \033[32mobjects created\033[0m\n\n"
	@ar vrus $@ $^
	@printf "\n|-> \033[32m$(NAME) complete\033[0m\n"

clean:
	@$(RM) -rf $(OBJDIR)

fclean: clean
	@$(RM) -f $(NAME)
	@printf "|-> \033[31m$(NAME) deleted\033[0m\n"

re: fclean all

.PHONY: all clean fclean re