# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokyrand <tokyrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/16 05:45:32 by tokyrand          #+#    #+#              #
#    Updated: 2026/09/16 05:59:17 by tokyrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = codexion

SRCS = simulation/codexion.c \
	   simulation/destroy_data_mutex.c \
	   simulation/ft_error.c \
	   simulation/ft_isnumber.c \
	   simulation/init_coders_utils.c \
	   simulation/init_coders.c \
	   simulation/init_data_mutex.c \
	   simulation/init_data_utils.c \
	   simulation/init_data.c \
	   simulation/init_dongles_utils.c \
	   simulation/init_dongles.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
HEADER = simulation/codexion.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re