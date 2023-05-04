# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teliet <teliet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:41:39 by teliet            #+#    #+#              #
#    Updated: 2023/05/04 19:35:41 by teliet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRC = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
 
OBJ = $(SRC:.cpp=.o)

CC = c++

HEADERS = -I ./

FLAGS = -Wall -Wextra -Werror -std=c++98 -g3


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