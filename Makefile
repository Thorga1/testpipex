# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tordner <tordner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:28:00 by tordner           #+#    #+#              #
#    Updated: 2024/12/16 19:43:26 by tordner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	pipex.c			\
			utils.c			\
			file_handler.c	\
			errors.c		\
			get_env.c		\
			ft_split.c

OBJ		=	$(SRC:.c=.o)

NAME	=	pipex

HEADERS	=	-I includes

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			cc  -Wall -Wextra -Werror $(HEADERS) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
