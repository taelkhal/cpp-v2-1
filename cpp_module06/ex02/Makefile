# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 17:29:39 by taelkhal          #+#    #+#              #
#    Updated: 2024/01/30 17:32:20 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Generate

CC = c++

CXXFLAGS = -Wall -Wextra -Werror  -std=c++98

SRCS = main.cpp Generate.cpp

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all