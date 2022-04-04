NAME = pipex
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = utils.c \

SRCS_PIPEX = main.c \

OBJS = $(SRCS:.c=.o)

OBJS_PIPEX = $(SRCS_PIPEX:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I./Libft/. -I./gnl/. -c $< -o $@

all:
	@${MAKE} --no-print-directory $(NAME)

$(NAME): $(OBJS) $(OBJS_PIPEX) ./Libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_PIPEX) ./Libft/libft.a -o $(NAME)


./Libft/libft.a:
	$(MAKE) -C ./Libft bonus


clean:
	$(MAKE) -C ./Libft $@
	$(RM) $(OBJS) $(OBJS_PIPEX)

fclean: clean
	$(MAKE) -C ./Libft $@
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
