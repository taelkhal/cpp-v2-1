# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 13:48:10 by taelkhal          #+#    #+#              #
#    Updated: 2024/02/19 13:49:15 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CPP = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all