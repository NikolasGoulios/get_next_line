# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 13:22:36 by ngoulios          #+#    #+#              #
#    Updated: 2024/08/12 13:31:04 by ngoulios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line_bonus
CC = cc 
FLAGS = -Wall -Werror -Wextra -fsanitize=address

SRC = get_next_line_utils_bonus.c get_next_line_bonus.c mainbonus.c

OBJECTS = $(SRC:.c=.o)

%.o: %.c 
	$(CC) $(FLAGS) -I. -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs lib$(NAME).a $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME) lib$(NAME).a

re: fclean all

.PHONY: all clean fclean re
