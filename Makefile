# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 20:10:25 by marvin            #+#    #+#              #
#    Updated: 2024/12/02 20:10:25 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.a

SRC			= get_next_line.c \
				get_next_line_utils.c

OBJ			= $(SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
			@$(RM) $(OBJ)

fclean:
			@$(RM) $(NAME) $(OBJ)

re: 		fclean all

.PHONY:		all clean fclean re