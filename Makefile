# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 23:46:32 by cnolte            #+#    #+#              #
#    Updated: 2018/06/10 10:02:04 by cnolte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRCS = main.cpp game.cpp gameObject.cpp ship.cpp bullet.cpp
OBJS = main.o game.o gameObject.o ship.o bullet.o

CXX = clang++
CXXFLAGS = -lncurses

all: $(NAME)

$(NAME):
	@$(CXX) -c $(SRCS)
	@$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)
	@echo [INFO] $@ "compiled successfully."

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re
