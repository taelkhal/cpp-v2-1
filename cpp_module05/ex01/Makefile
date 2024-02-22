# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 16:08:33 by taelkhal          #+#    #+#              #
#    Updated: 2024/01/15 16:30:47 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Form.cpp  Bureaucrat.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all