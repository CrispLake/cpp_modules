# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 12:50:22 by emajuri           #+#    #+#              #
#    Updated: 2023/05/16 17:12:51 by emajuri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = test

SRC = tests.cpp Account.cpp

OBJ = $(addprefix obj/,$(SRC:%.cpp=%.o))

DEP = $(OBJ:%.o=%.d)

#folders
INC = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

#flags
WWW = -Wall -Wextra -Werror
FLAGS = $(WWW) -std=c++98

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

$(OBJ_DIR)/%.o: %.cpp
	c++ $(FLAGS) -MMD -c $< -o $@

re: fclean all
