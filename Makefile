#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ireva <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 17:26:49 by ireva             #+#    #+#              #
#    Updated: 2017/10/10 12:13:15 by ireva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

SRC = filler.c my_turn.c work_with_plateau.c work_with_ned.c work_with_piece.c get_next_line.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

LIBFT_I = ./libft/libft.h

LIBFT = ./libft/

all: $(LIBFT)libft.a $(NAME)

$(NAME):  $(OBJECTS)
	@gcc $(OBJECTS) $(LIBFT)libft.a -o $(NAME)
	@echo "\033[31mCompleted!!!\033[0m"

%.o: %.c
	@gcc -c $< $(CFLAGS) -o $@

$(LIBFT)libft.a:
	@make -C $(LIBFT)

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all