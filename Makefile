NAME = codexion

SRCS = codexion_simulation/cleanup.c \
	   codexion_simulation/init_utils.c \
	   codexion_simulation/init.c \
	   codexion_simulation/main.c \
	   codexion_simulation/simulation.c \
	   codexion_simulation/simulation_helper.c \
	   codexion_simulation/simulation_helper_2.c \
	   codexion_simulation/simulation_helper_3.c \
	   codexion_simulation/init_helpers.c \
	   codexion_simulation/get_time_ms.c \
	   codexion_simulation/log_message.c \
	   codexion_simulation/monitor.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
HEADER = codexion_simulation/codexion.h

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