# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 12:50:22 by emajuri           #+#    #+#              #
#    Updated: 2023/05/18 16:51:42 by emajuri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = main
SRC = $(NAME).cpp Harl.cpp
OBJ = $(addprefix obj/,$(SRC:%.cpp=%.o))
DEP = $(OBJ:%.o=%.d)

#folders
INC = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

#flags
# WWW = -Wall -Wextra -Werror
FLAGS = $(WWW) -std=c++98 -I $(INC)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

-include $(DEP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	c++ $(FLAGS) -MMD -c $< -o $@

re: fclean all
