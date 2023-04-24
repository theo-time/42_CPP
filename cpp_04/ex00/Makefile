# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theo <theo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:41:39 by teliet            #+#    #+#              #
#    Updated: 2023/04/24 11:32:15 by theo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

HEADERS = -I ./

FLAGS = -Wall -Wextra -Werror -std=c++98


all: ${NAME}
 
$(NAME): $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
debug: $(LIBS) clean
	$c(CC) $(SRC) $(HEADERS) -o $(NAME) # -fsanitize=thread

%.o: %.cpp
	$(CC) $(HEADERS)  $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f ${OBJ}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all