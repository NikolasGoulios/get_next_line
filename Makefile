# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 15:21:08 by ngoulios          #+#    #+#              #
#    Updated: 2024/08/06 13:15:03 by ngoulios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = get_next_line
CC = cc 
FLAGS = -Wall -Werror -Wextra 

SRC = get_next_line_utils.c get_next_line.c main.c

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